# save emmc_dump_$@.bin first at ~/Bind folder

rm -rf ~/Documents/phoenix/romcode/simulation/flash_data/emmc_flash/$@
mkdir ~/Documents/phoenix/romcode/simulation/flash_data/emmc_flash/$@
cp ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/signature.bin ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/
cp ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/hwsetting_* ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/
cp ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/sha256*.bin ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/
cp ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/fsbl*.bin ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/
cp ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/* ~/Documents/phoenix/romcode/simulation/flash_data/emmc_flash/$@
dd bs=128K count=1 if=/dev/zero of=~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/d.bin
cat ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/d.bin /home/parallels/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot.emmc/examples/flash_writer_u/Bind/emmc_dump_$@.bin > ~/Documents/phoenix/romcode/simulation/flash_data/emmc_flash/$@/bind.bin
/home/parallels/Documents/phoenix/romcode/src/bin/tools/bin2hex_e.pl ~/Documents/phoenix/romcode/simulation/flash_data/emmc_flash/$@/bind.bin ~/Documents/phoenix/romcode/simulation/flash_data/emmc_flash/$@/bind.bin.hex
