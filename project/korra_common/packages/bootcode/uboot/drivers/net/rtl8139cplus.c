/*
 * rtl8139.c : U-Boot driver for the RealTek RTL8139
 *
 * Masami Komiya (mkomiya@sonare.it)
 *
 * Most part is taken from rtl8139.c of etherboot
 *
 */

/* rtl8139.c - etherboot driver for the Realtek 8139 chipset

  ported from the linux driver written by Donald Becker
  by Rainer Bawidamann (Rainer.Bawidamann@informatik.uni-ulm.de) 1999

  This software may be used and distributed according to the terms
  of the GNU Public License, incorporated herein by reference.

  changes to the original driver:
  - removed support for interrupts, switching to polling mode (yuck!)
  - removed support for the 8129 chip (external MII)

*/

/*********************************************************************/
/* Revision History						     */
/*********************************************************************/

/*
  28 Dec 2002	ken_yap@users.sourceforge.net (Ken Yap)
     Put in virt_to_bus calls to allow Etherboot relocation.

  06 Apr 2001	ken_yap@users.sourceforge.net (Ken Yap)
     Following email from Hyun-Joon Cha, added a disable routine, otherwise
     NIC remains live and can crash the kernel later.

  4 Feb 2000	espenlaub@informatik.uni-ulm.de (Klaus Espenlaub)
     Shuffled things around, removed the leftovers from the 8129 support
     that was in the Linux driver and added a bit more 8139 definitions.
     Moved the 8K receive buffer to a fixed, available address outside the
     0x98000-0x9ffff range.  This is a bit of a hack, but currently the only
     way to make room for the Etherboot features that need substantial amounts
     of code like the ANSI console support.  Currently the buffer is just below
     0x10000, so this even conforms to the tagged boot image specification,
     which reserves the ranges 0x00000-0x10000 and 0x98000-0xA0000.  My
     interpretation of this "reserved" is that Etherboot may do whatever it
     likes, as long as its environment is kept intact (like the BIOS
     variables).  Hopefully fixed rtl_poll() once and for all.	The symptoms
     were that if Etherboot was left at the boot menu for several minutes, the
     first eth_poll failed.  Seems like I am the only person who does this.
     First of all I fixed the debugging code and then set out for a long bug
     hunting session.  It took me about a week full time work - poking around
     various places in the driver, reading Don Becker's and Jeff Garzik's Linux
     driver and even the FreeBSD driver (what a piece of crap!) - and
     eventually spotted the nasty thing: the transmit routine was acknowledging
     each and every interrupt pending, including the RxOverrun and RxFIFIOver
     interrupts.  This confused the RTL8139 thoroughly.	 It destroyed the
     Rx ring contents by dumping the 2K FIFO contents right where we wanted to
     get the next packet.  Oh well, what fun.

  18 Jan 2000	mdc@thinguin.org (Marty Connor)
     Drastically simplified error handling.  Basically, if any error
     in transmission or reception occurs, the card is reset.
     Also, pointed all transmit descriptors to the same buffer to
     save buffer space.	 This should decrease driver size and avoid
     corruption because of exceeding 32K during runtime.

  28 Jul 1999	(Matthias Meixner - meixner@rbg.informatik.tu-darmstadt.de)
     rtl_poll was quite broken: it used the RxOK interrupt flag instead
     of the RxBufferEmpty flag which often resulted in very bad
     transmission performace - below 1kBytes/s.

*/

#include <common.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <asm/arch/system.h>

#define REG_BASE    0xb8016000
#define RTL_TIMEOUT	100000
#define HZ 1000
#define TX_TIMEOUT  (6*HZ)
/* Condensed operations for readability. */
#define currticks()	get_timer(0)

#define ETH_FRAME_LEN		1514
#define ETH_ALEN		6
#define ETH_ZLEN		64

//#define TWO_BYTE_ALIGN
#ifdef TWO_BYTE_ALIGN
#define RX_OFFSET 	2
#else
#define RX_OFFSET 	0
#endif

/* PCI Tuning Parameters
   Threshold is bytes transferred to chip before transmission starts. */
#define TX_FIFO_THRESH 256	/* In bytes, rounded down to 32 byte units. */
#define RX_FIFO_THRESH	4	/* Rx buffer level before first PCI xfer.  */
#define NUM_TX_DESC	32	/* Number of Tx descriptor registers. */
#define NUM_RX_DESC	32	/* Number of Rx descriptor registers */
#define RX_BUF_SIZE	1536	/* Rx Buffer size */
//#define RX_BUF_SIZE	2048	/* Rx Buffer size */

//#define TX_BUF_SIZE	ETH_FRAME_LEN + 4	/* FCS is added by the chip */
//#define RX_BUF_LEN_IDX 0	/* 0, 1, 2 is allowed - 8,16,32K rx buffer */
//#define RX_BUF_LEN (8192 << RX_BUF_LEN_IDX)
#define RX_BUF_LEN 4096

//#define DEBUG_RTL8139
//#define DEBUG_RTL8139_TX
//#define DEBUG_RTL8139_RX



/* Symbolic offsets to registers. */
enum RTL8139_registers {
	MAC0=0,			/* Ethernet hardware address. */
	MAR0=8,			/* Multicast filter. */
	OKCNT=0x10,		/* Transmit/receive ok count */
	ERRCNT=0x14,
	MISSCNT=0x18,
	COLCNT=0x1C,
	ChipCmd=0x3B, RxBufPtr=0x38, RxBufAddr=0x3A,
	IntrMask=0x3C, IntrStatus=0x3E,
	TxConfig=0x40, RxConfig=0x44,
	MediaStatus=0x58,
	MultiIntr=0x5C,
	TxFDP1=0x100, TxCDO1=0x104, RxFDP=0x1f0, RxCDO_RingSize=0x1f4, RxRingSize=0x1f6,
	Rx_Pse_Des_Thres_h=0x22c, EthrntRxCPU_Des_Num=0x230, Pse_Des_Thres_on=0x231, Rx_Pse_Des_Thres_off=0x232, EthrntRxCPU_Des_Num_h=0x233,
	IO_CMD=0x234, Ethernet_Ctrl=0x23c, Ethernet_Ctrl1=0x24c,
	/* from 0x84 onwards are a number of power management/wakeup frame
	 * definitions we will probably never need to know about.  */
};

enum ChipCmdBits {
	CmdReset=0x1, RxCS=0x2,
};

/* Interrupt register bits, using my own meaningful names. */
enum IntrStatusBits {
	TxErr=0x60, TxOK=0x40,
	RxRDU=0x20, RxFIFOOver=0x10, RxRunt=0x04, RxOK=0x01,
};

enum MediaStatusBits {
	MSRRxFlowEnable=0x40, MSRTxFlowEnable=0x20, MSRSpeed10=0x08,
	MSRLinkFail=0x04, MSRTxPauseFlag=0x02, MSRRxPauseFlag=0x01,
};

enum MIIBMCRBits {
	BMCRReset=0x8000, BMCRSpeed100=0x2000, BMCRNWayEnable=0x1000,
	BMCRRestartNWay=0x0200, BMCRDuplex=0x0100,
};

/* Bits in RxConfig. */
enum rx_mode_bits {
	RxCfgWrap=0x80,
	AcceptErr=0x20, AcceptRunt=0x10, AcceptBroadcast=0x08,
	AcceptMulticast=0x04, AcceptMyPhys=0x02, AcceptAllPhys=0x01,
};

/* Bits in TxConfig. */
enum tx_mode_bits {
	TCR_IFG=0x3,
    TCR_IFG_OFFSET=10,
    TCR_NORMAL=0x0,
    TCR_LOOPBACK=0x3,
    TCR_MODE_OFFSET=8,
};

/* Rx flow control descriptor threshold (0~31) */
enum rx_thresholds_bits {
    THVAL=0x8,
    THOFFVAL=0x16,
    RX_FC_THRESHOLD=0x8,
    EthrntRxCPU_Des_Num_offset=0x24,
    Rx_Pse_Des_Thres_offset=0x8,
};

/* 32 descriptors */
enum rx_ring_size_bits {
	Des_Size=0x1f00,
};

enum _DescStatusBit {
	OWNbit = 0x80000000,
	EORbit = 0x40000000,
	FSbit = 0x20000000,
	LSbit = 0x10000000,
};

struct desc {
	u32 status;
	u32 buf_addr;
	u32 vlan_tag;
	u32 buf_Haddr;
};

/* Define the TX Descriptor */
#ifdef CONFIG_NONCACHE_ALLOCATION
static u8 *tx_ring = NULL;
#else
static u8 tx_ring[NUM_TX_DESC * sizeof(struct desc) + 256];
/*	__attribute__ ((aligned(256))); */
#endif

/* Create a static buffer of size RX_BUF_SZ for each
TX Descriptor.	All descriptors point to a
part of this buffer */
static unsigned char txb[NUM_TX_DESC * RX_BUF_SIZE] __attribute__((aligned(4)));;

/* Define the RX Descriptor */
#ifdef CONFIG_NONCACHE_ALLOCATION
static u8 *rx_ring = NULL;
#else
static u8 rx_ring[NUM_RX_DESC * sizeof(struct desc) + 256];
/*  __attribute__ ((aligned(256))); */
#endif

/* Create a static buffer of size RX_BUF_SZ for each
RX Descriptor	All descriptors point to a
part of this buffer */
static unsigned char rxb[NUM_RX_DESC * RX_BUF_SIZE] __attribute__((aligned(4)));;

struct rtl8139_private {
	void *mmio_addr;	/* memory map physical address */
	int chipset;
	unsigned long cur_rx;	/* Index into the Rx descriptor buffer of next Rx pkt. */
	unsigned long cur_tx;	/* Index into the Tx descriptor buffer of next Rx pkt. */
	unsigned long dirty_tx;
	unsigned char *TxDescArrays;	/* Index of Tx Descriptor buffer */
	unsigned char *RxDescArrays;	/* Index of Rx Descriptor buffer */
	struct desc *TxDescArray;	/* Index of 256-alignment Tx Descriptor buffer */
	struct desc *RxDescArray;	/* Index of 256-alignment Rx Descriptor buffer */
	unsigned char *RxBufferRings;	/* Index of Rx Buffer  */
	unsigned char *RxBufferRing[NUM_RX_DESC];	/* Index of Rx Buffer array */
	unsigned char *Tx_skbuff[NUM_TX_DESC];
};

static int ioaddr = REG_BASE;

static int rtl8139_probe(struct eth_device *dev, bd_t *bis);
static void rtl_init_ring(struct eth_device *dev);
static void rtl_reset(struct eth_device *dev);
int rtl_transmit(struct eth_device *dev, void *packet, int length);
static int rtl_poll(struct eth_device *dev);
static void rtl_disable(struct eth_device *dev);
#ifdef CONFIG_MCAST_TFTP/*  This driver already accepts all b/mcast */
static int rtl_bcast_addr (struct eth_device *dev, u8 bcast_mac, u8 set)
{
	return (0);
}
#endif

void mdio_write(int RegAddr, int value)
{
	int i;

	rtd_outl(ioaddr + MultiIntr, 0x84000000 | (RegAddr & 0xFF) << 16 | value);
	udelay(1000);

	for (i = 2000; i > 0; i--) {
		/* Check if the RTL8139 has completed writing to the specified MII register */
		if (!(rtd_inl(ioaddr + MultiIntr) & 0x80000000)) {
			break;
		} else {
			udelay(100);
		}
	}
}

int mdio_read(int RegAddr)
{
	int i, value = -1;

	rtd_outl(ioaddr + MultiIntr, 0x04000000 | (RegAddr & 0xFF) << 16);
	udelay(1000);

	for (i = 2000; i > 0; i--) {
		/* Check if the RTL8169 has completed retrieving data from the specified MII register */
		if (rtd_inl(ioaddr + MultiIntr) & 0x80000000) {
			value = (int) (rtd_inl(ioaddr + MultiIntr) & 0xFFFF);
			break;
		} else {
			udelay(100);
		}
	}
	return value;
}

int rtl8139_initialize(bd_t *bis)
{
	struct eth_device *dev;
	struct rtl8139_private *priv;

	dev = (struct eth_device *)malloc(sizeof *dev);
	if (!dev) {
			printf("Can not allocate memory of rtl8139\n");
			return 0;
	}
	memset(dev, 0, sizeof(*dev));

	priv = (struct rtl8139_private *)malloc (sizeof (*priv));
	if (!priv) {
			printf("Can not allocate memory of rtl8139\n");
			return 0;
	}
	memset(priv, 0, sizeof *priv);

#ifdef CONFIG_NONCACHE_ALLOCATION
	tx_ring = (u8 *)malloc_noncache(NUM_TX_DESC * sizeof(struct desc) + 256);
	rx_ring = (u8 *)malloc_noncache(NUM_RX_DESC * sizeof(struct desc) + 256);
#endif

	sprintf (dev->name, "RTL8139CPLUS");
	dev->priv = priv;
	dev->iobase = ioaddr;
	dev->init = rtl8139_probe;
	dev->halt = rtl_disable;
	dev->send = rtl_transmit;
	dev->recv = rtl_poll;
#ifdef CONFIG_MCAST_TFTP
	dev->mcast = rtl_bcast_addr;
#endif

	printf ("rtl8139: REALTEK RTL8139 @0x%x\n", dev->iobase);

	eth_register (dev);

	udelay (10 * 1000);

	return 1;
}

static int rtl8139_probe(struct eth_device *dev, bd_t *bis)
{
	rtl_init_ring(dev);
	rtl_reset(dev);

//	if (rtd_inb(ioaddr + MediaStatus) & MSRLinkFail) {
	if (rtd_inl(ioaddr + MediaStatus) & (MSRLinkFail<<24)) {
		printf("Cable not connected or other link failure\n");
		return -1 ;
	}

	return 0;
}

static void set_rx_mode(struct eth_device *dev) {
	unsigned int mc_filter[2];
	int rx_mode;
	/* !IFF_PROMISC */
	rx_mode = AcceptBroadcast | AcceptMulticast | AcceptMyPhys;
	mc_filter[1] = mc_filter[0] = 0xffffffff;

	rtd_outl(ioaddr + RxConfig, rx_mode);

	rtd_outl(ioaddr + MAR0 + 0, mc_filter[0]);
	rtd_outl(ioaddr + MAR0 + 4, mc_filter[1]);
}

static void rtl_init_ring(struct eth_device *dev)
{
	int i;
	struct rtl8139_private *cp = dev->priv;

	cp->TxDescArrays = tx_ring;
	/* Tx Desscriptor needs 256 bytes alignment; */
	cp->TxDescArray = (struct desc *) ((unsigned long)(cp->TxDescArrays + 255) & ~255);

	cp->RxDescArrays = rx_ring;
	/* Rx Desscriptor needs 256 bytes alignment; */
	cp->RxDescArray = (struct desc *) ((unsigned long)(cp->RxDescArrays + 255) & ~255);

	cp->cur_rx = 0;
	cp->cur_tx = 0;
	cp->dirty_tx = 0;
	memset(cp->TxDescArray, 0x0, NUM_TX_DESC * sizeof(struct desc));
	memset(cp->RxDescArray, 0x0, NUM_RX_DESC * sizeof(struct desc));

	for (i = 0; i < NUM_TX_DESC; i++) {
//		cp->Tx_skbuff[i] = &txb[i];
		cp->Tx_skbuff[i] = &txb[i * RX_BUF_SIZE];
	}

	for (i = 0; i < NUM_RX_DESC; i++) {
		if (i == (NUM_RX_DESC - 1))
			cp->RxDescArray[i].status =
				OWNbit | EORbit | RX_BUF_SIZE;
		else
			cp->RxDescArray[i].status =
				OWNbit | RX_BUF_SIZE;

		cp->RxBufferRing[i] = &rxb[i * RX_BUF_SIZE];
		cp->RxDescArray[i].buf_addr = (u32)cp->RxBufferRing[i];
		flush_cache((unsigned long)cp->RxBufferRing[i], RX_BUF_SIZE);
	}

	/* Construct a perfect filter frame with the mac address as first match
	 * and broadcast for all others */
	for (i = 0; i < 192; i++)
		txb[i] = 0xFF;

	txb[0] = dev->enetaddr[0];
	txb[1] = dev->enetaddr[1];
	txb[2] = dev->enetaddr[2];
	txb[3] = dev->enetaddr[3];
	txb[4] = dev->enetaddr[4];
	txb[5] = dev->enetaddr[5];
}

static void rtl_reset(struct eth_device *dev)
{
	int i;
	struct rtl8139_private *cp = dev->priv;

	/* Reset */
//	rtd_outb(ioaddr + ChipCmd, CmdReset);
	rtd_outl(ioaddr + RxBufPtr, CmdReset);

	/* Give the chip 10ms to finish the reset. */
	for (i=0; i<100; ++i){
//		if ((rtd_inb(ioaddr + ChipCmd) & CmdReset) == 0) break;
		if ((rtd_inl(ioaddr + RxBufPtr) & CmdReset) == 0) break;
		udelay (100); /* wait 100us */
	}

	/* Enable receive checksum */
//	rtd_outb(ioaddr + ChipCmd, RxCS);
	rtd_outl(ioaddr + RxBufPtr, RxCS);

	/* Get MAC address and set MAC address*/
	eth_setenv_enetaddr("ethaddr", dev->enetaddr);
//	for (i = 0; i < ETH_ALEN; i++)
//		rtd_outb(ioaddr + MAC0 + i, dev->enetaddr[i]);
	rtd_outl(ioaddr + MAC0, dev->enetaddr[0]<<24|dev->enetaddr[1]<<16|dev->enetaddr[2]<<8|dev->enetaddr[3]);
	rtd_outl(ioaddr + MAC0 + 4, dev->enetaddr[4]<<24|dev->enetaddr[5]<<16);


#ifdef DEBUG_RTL8139
	printf("MAC Address");
	for (i = 0; i < ETH_ALEN; i++)
		printf(":%02x", dev->enetaddr[i]);
	putc('\n');

	/* Print out some hardware info */
	printf("%s: at ioaddr 0x%x\n", dev->name, ioaddr);
#endif

	/* Reset interrupt mask and interrupt status */
	rtd_outl(ioaddr + IntrMask, 0x3fffff);

	/* Setup descriptor */
	rtd_outl(ioaddr + RxFDP, (uint)cp->RxDescArray);
	rtd_outl(ioaddr + TxFDP1, (uint)cp->TxDescArray);
	rtd_outl(ioaddr + TxCDO1, 0);

#ifdef TWO_BYTE_ALIGN
	rtd_outl(ioaddr + Ethernet_Ctrl, rtd_inl(ioaddr + Ethernet_Ctrl) | 0x4);
#endif

	/* Set Rx mode => accept no error packets */
	set_rx_mode(dev);

	/* Set Tx config */
	rtd_outl(ioaddr + TxConfig, (TCR_IFG<<TCR_IFG_OFFSET)|(TCR_NORMAL<<TCR_MODE_OFFSET));

	/* Set Rx threshold */
//	rtd_outb(ioaddr + Pse_Des_Thres_on, THVAL);
//  rtd_outb(ioaddr + Rx_Pse_Des_Thres_off, THOFFVAL);
//  rtd_outb(ioaddr + Rx_Pse_Des_Thres_h, 0);

	/* Rx descriptor Size */
//  rtd_outb(ioaddr + EthrntRxCPU_Des_Num, NUM_RX_DESC-1);
//  rtd_outb(ioaddr + EthrntRxCPU_Des_Num_h, 0);
//	rtd_outw(ioaddr + RxRingSize, Des_Size);
	rtd_outl(ioaddr + Rx_Pse_Des_Thres_h, 0);
	rtd_outl(ioaddr + EthrntRxCPU_Des_Num, (NUM_RX_DESC-1)<<24 | THVAL <<16 | THOFFVAL<<8);
	rtd_outl(ioaddr + RxCDO_RingSize, Des_Size);

	/* Enable flow control*/
//	rtd_outb(ioaddr + MediaStatus, MSRRxFlowEnable | MSRTxFlowEnable);
	rtd_outl(ioaddr + MediaStatus, (MSRRxFlowEnable | MSRTxFlowEnable)<<24);

	/* Reset PHY */
//	mdio_write(0, BMCRReset);
	/* Fix 10M */
//	mdio_write(0, BMCRDuplex);
	mdio_write(0, BMCRSpeed100 | BMCRDuplex); //fix 100M full duplex

	rtd_outl(ioaddr + Ethernet_Ctrl1, 0x52080);

	/* Enable RX */
	//rtd_outl(ioaddr + IO_CMD, 0x40080031);
	rtd_outl(ioaddr + IO_CMD, 0x40080020);
}

int rtl_transmit(struct eth_device *dev, void *packet, int length)
{
	unsigned char *ptxb;
	unsigned int len = length;
	unsigned int to;
	struct rtl8139_private *cp = dev->priv;
	int ret;
	int entry = cp->cur_tx % NUM_TX_DESC;

#ifdef DEBUG_RTL8139_TX
	int stime = currticks();
	printf ("%s\n", __FUNCTION__);
	printf("sending %d bytes\n", len);
#endif

	ptxb = cp->Tx_skbuff[entry];
#ifdef DEBUG_RTL8139_TX
	printf("entry = %d, buff addr = %x, desc addr = %x\n", entry, (u32)ptxb, &cp->TxDescArray[entry]);
#endif
	memcpy((char *)ptxb, (char *)packet, (int)length);

	while (len < ETH_ZLEN) {
		ptxb[len++] = '\0';
	}
	/* Fluch cache: TX buffer */
	flush_cache((unsigned long)ptxb, len);

	cp->TxDescArray[entry].buf_Haddr = 0;
	cp->TxDescArray[entry].buf_addr = (uint)ptxb;
	cp->TxDescArray[entry].status &= (~0x00000fff);
	cp->TxDescArray[entry].status |= len;
	wmb();

	if ((entry) != (NUM_TX_DESC - 1)) {
		cp->TxDescArray[entry].status |= (OWNbit | FSbit | LSbit | (1<<23));
	} else {
		cp->TxDescArray[entry].status |= (OWNbit | EORbit | FSbit | LSbit | (1<<23));
	}
	wmb();

	cp->cur_tx++;

	rmb();
	/* Enable TX/RX */
	rtd_outl(ioaddr + IO_CMD, 0x40080031);

	to = currticks() + TX_TIMEOUT;
	do {
	} while ((cp->TxDescArray[entry].status & OWNbit)
				&& (currticks() < to));	/* wait */

#if DEBUG_RTL8139_TX
	printf("status = %x\n", cp->TxDescArray[entry].status);
#endif

	if (currticks() >= to) {
#ifdef DEBUG_RTL8139_TX
		puts ("tx timeout/error\n");
		printf ("%s elapsed time : %d\n", __FUNCTION__, currticks()-stime);
#endif
		ret = 0;
	} else {
#ifdef DEBUG_RTL8139_TX
		puts("tx done\n");
#endif
		ret = length;
	}
	/* Delay to make net console (nc) work properly */
	udelay(20);
	return ret;
}

static int rtl_poll(struct eth_device *dev)
{
	struct rtl8139_private *cp = dev->priv;
	unsigned int status;
	int cur_rx;
	int length = 0;

//	status = rtd_inw(ioaddr + IntrStatus);
	status = rtd_inl(ioaddr + IntrMask) & 0xFFFF;
	rtd_outl(ioaddr + IntrMask, 0xffff);

#ifdef DEBUG_RTL8139_RX
	printf("rtl_poll: status = %hX ", status);
#endif

	if(status & RxRDU) {
		printf("error:RX desc. unavailable ,status = 0x%x \n",status);
	}

	if(status & RxRunt) {
        printf("error:RX runt ,status = 0x%x \n",status);
	}

	if(status & RxFIFOOver) {
		printf("error:RX FIFO full ,status = 0x%x \n",status);
		rtl_init_ring(dev);
		rtl_reset(dev);
		return 0;
	}

	cur_rx = cp->cur_rx;

	if ((cp->RxDescArray[cur_rx].status & OWNbit) == 0) {
			unsigned char rxdata[RX_BUF_LEN];
			length = (int) (cp->RxDescArray[cur_rx].status & 0x7ff) - 4;

			memcpy(rxdata, cp->RxBufferRing[cur_rx]+RX_OFFSET, length);

#ifdef DEBUG_RTL8139_RX
			printf("Descriptor%d: status= 0x%8x, rx buffer address= 0x%8x\n",
					cur_rx, cp->RxDescArray[cur_rx].status, cp->RxDescArray[cur_rx].buf_addr);

			int i;

			for (i=0; i<32; i++) {
					printf(" %02x", rxdata[i]) ;
			}
			printf("\n" ) ;
			printf("OK cnt=0x%x, Err cnt=0x%x, Miss cnt=0x%x, Col cnt=0x%x\n", OKCNT, ERRCNT, MISSCNT, COLCNT);
#endif

			NetReceive(rxdata, length);

			if (cur_rx == NUM_RX_DESC - 1)
				cp->RxDescArray[cur_rx].status = OWNbit | EORbit | RX_BUF_SIZE;
			else
				cp->RxDescArray[cur_rx].status = OWNbit | RX_BUF_SIZE;
			cp->RxDescArray[cur_rx].buf_addr = (u32)cp->RxBufferRing[cur_rx];
			flush_cache((unsigned long)cp->RxBufferRing[cur_rx], RX_BUF_SIZE);

//			rtd_outb(ioaddr + EthrntRxCPU_Des_Num, cur_rx);
			rtd_outl(ioaddr + EthrntRxCPU_Des_Num, cur_rx<<24);

			cur_rx = (cur_rx + 1) % NUM_RX_DESC;
			cp->cur_rx = cur_rx;

			/* Reset interrupt mask and interrupt stauts */
			rtd_outl(ioaddr + IntrMask, 0x3fffff);

			return 1;
	}

	cp->cur_rx = cur_rx;
	return 0;
}

static void rtl_disable(struct eth_device *dev)
{
	int i;
	struct rtl8139_private *cp = dev->priv;

	/* Reset the chip */
//	rtd_outb(ioaddr + ChipCmd, CmdReset);
	rtd_outl(ioaddr + RxBufPtr, CmdReset);

	/* Reset interrupt mask and interrupt stauts */
	rtd_outl(ioaddr + IntrMask, 0xffff);

	/* Disable IO command */
	rtd_outl(ioaddr + IO_CMD, 0x0);

	/* Give the chip 10ms to finish the reset. */
	for (i=0; i<100; ++i){
//		if ((rtd_inb(ioaddr + ChipCmd) & CmdReset) == 0) break;
		if ((rtd_inl(ioaddr + RxBufPtr) & CmdReset) == 0) break;
		udelay (100); /* wait 100us */
	}

	cp->TxDescArrays = NULL;
	cp->RxDescArrays = NULL;
	cp->TxDescArray = NULL;
	cp->RxDescArray = NULL;
	for (i = 0; i < NUM_RX_DESC; i++) {
		cp->RxBufferRing[i] = NULL;
	}
}
