#include <common.h>
#include <command.h>
#include <asm/arch/system.h>
#include <asm/arch/flash_writer_u/mcp.h>
#include <asm/arch/flash_writer_u/big_int.h>
#include <asm/arch/flash_writer_u/big_util.h>

/************************************************************************
 *  Public variables
 ************************************************************************/
static unsigned int alloc_count;

/************************************************************************
 *  Static variables
 ************************************************************************/
static unsigned int alloc_current;

/************************************************************************
 *  Function body
 ************************************************************************/
void * my_malloc(unsigned int NBYTES)
{
    void *p;

    if ((alloc_count + NBYTES) > SECURE_MAX_ALLOC_SIZE) {
        return NULL;
    }

    if (alloc_count == 0) {
        alloc_current = SECURE_MALLOC_BASE;
    }

    p = (void *)(alloc_current);

    if (NBYTES & 0x3) {
        NBYTES = ((NBYTES >> 2) << 2) + 0x4;
    }

    alloc_current += NBYTES;
    alloc_count += NBYTES;

    return p;
}

void my_freeAll(void)
{
    alloc_count = 0;
    alloc_current = SECURE_MALLOC_BASE;
}

unsigned int do_RSA( const unsigned int signature_addr,
                     const unsigned int rsa_key_addr,
                     const unsigned int output_addr )
{
    BI *base, *exp, *mod, *res;
    unsigned int t1, tmp;
    int i;
    unsigned char * ptr;
    const char algo_id[19] = {
        0x30, 0x31, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86,
        0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
        0x00, 0x04, 0x20};

    // necessary
    alloc_count = 0;
    alloc_current = SECURE_MALLOC_BASE;

    base = InPutFromAddr((unsigned char *)signature_addr, RSA_SIGNATURE_LENGTH);
    if(base == NULL) {
        my_freeAll();
        return NULL;
    }

    mod = InPutFromAddr((unsigned char *)rsa_key_addr, RSA_SIGNATURE_LENGTH);
    if(mod == NULL) {
        my_freeAll();
        return NULL;
    }

    // public exponent is always 65537
    exp = move_p(65537);
    if(exp == NULL) {
        my_freeAll();
        return NULL;
    }

    res = Exp_Mod(base, exp, mod);
    if(res == NULL) {
        my_freeAll();
        return NULL;
    }

    OutPutToAddr(res, (unsigned char *)output_addr, 1);

    // bypass PKCS#1 v1.5 block format
    t1 = output_addr;
    ptr = (unsigned char *)t1;
    if ((*ptr == 0) && (*(ptr+1) == 0x1)) {
        // skip padding
        // (padding format: 00 01 ff ff ff ... 00)
        t1 += 2;
        ptr += 2;

        while (*ptr == 0xff) {
            ptr++;
            t1++;
        }

        if (*ptr == 0) {
            ptr++;
            t1++;
        }

        tmp = t1;

        // skip digest algorithm identifier
        for (i = 0; i < sizeof(algo_id); i++) {
            if (*ptr != algo_id[i]) {
                t1 = tmp;   // restore to previous postition
                break;
            }
            ptr++;
            t1++;
        }
    }

    my_freeAll();

    return t1;
}
