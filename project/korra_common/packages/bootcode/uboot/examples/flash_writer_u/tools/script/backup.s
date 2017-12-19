rm -rf ~/Documents/phoenix/romcode/simulation/flash_data/spi_flash/$@
mkdir ~/Documents/phoenix/romcode/simulation/flash_data/spi_flash/$@

cp ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/signature.bin ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/
cp ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/hwsetting_* ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/
cp ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/sha256*.bin ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/
cp ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/fsbl*.bin ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/
cp -rf ~/Documents/phoenix/flash_environment/bootcode/svn/bootcode/uboot/examples/flash_writer_u/Bind/* ~/Documents/phoenix/romcode/simulation/flash_data/spi_flash/$@
