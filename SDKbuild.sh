#!/bin/bash

#. $PWD/build.conf

usage(){
	echo "Usage"
	echo "	`echo $0 | cut -c 3-` [project] [config|build|clean|\$pkg-rebuild|\$pkg-reconfigure]"
	echo "	- help: show this message"
	echo "	- config: config project"
	echo "	- build : build project"
	echo "	- clean : clean project"
	echo "	- genfw : generate fw"
	echo "	- \$pkg-rebuild : for example, linux-rebuild will rebuild linux kernel"
	echo "	- \$pkg-reconfigure : for example, linux-reconfigure will reconfigure and rebuild the linux kernel"
	echo -e "	- \033[1;32mSupported Project List:\033[0m"
	echo -e "	 * \033[1;32mkorra_spi\033[0m"
	echo -e "	 * \033[1;32mkorra_fwupg\033[0m"
	echo -e "	 * \033[1;32mkorra_rescue\033[0m"
}

exit_build(){
	echo "$1"
	exit 1
}
#
#	remove_link()
#
#	$1: Project directory
#
remove_link(){
	rm -rf $1/prjPackages
	rm -rf $1/prjPatches
	rm -rf $1/prjConfigs
}

#
#	init_link()
#
#	$1: Project directory
#	$2: Build project
#
init_link(){
	PROJ_PATH=$1/$2
	PROJ_TOP=`echo $2 | cut -d "_" -f 1`
	PROJ_SUB=`echo $2 | cut -d "_" -f 2`

	[ -d $1/prjPackages ] && echo "Remove old $1/prjPackages" && rm -rf $1/prjPackages
	[ -d $1/prjPatches ] && echo "Remove old $1/prjPatches" && rm -rf $1/prjPatches
	[ -d $1/prjConfigs ] && echo "Remove old $1/prjConfigs" && rm -rf $1/prjConfigs
	
	mkdir -p $1/prjPackages
	chmod 777 $1/prjPackages
	mkdir -p $1/prjPatches
	chmod 777 $1/prjPatches
	mkdir -p $1/prjConfigs
	chmod 777 $1/prjConfigs

	#rebuild link
	tmpList=`ls $PROJ_PATH/packages`
	for file in $tmpList; do
		ln -s $PROJ_PATH/packages/$file $1/prjPackages
	done
	tmpList=`ls $PROJ_PATH/patches`
	for file in $tmpList; do
		ln -s $PROJ_PATH/patches/$file $1/prjPatches
	done
	tmpList=`ls $PROJ_PATH/configs`
	for file in $tmpList; do
		ln -s $PROJ_PATH/configs/$file $1/prjConfigs
	done
	if [ -d $1/${PROJ_TOP}_common/packages ]; then
		tmpList=`ls $1/${PROJ_TOP}_common/packages`
		for file in $tmpList; do
			ln -s $1/${PROJ_TOP}_common/packages/$file $1/prjPackages
		done
	fi
	if [ -d $1/${PROJ_TOP}_common/patches ]; then
		tmpList=`ls $1/${PROJ_TOP}_common/patches`
		for file in $tmpList; do
			ln -s $1/${PROJ_TOP}_common/patches/$file $1/prjPatches
		done
	fi
	if [ -d $1/${PROJ_TOP}_common/configs ]; then
		tmpList=`ls $1/${PROJ_TOP}_common/configs`
		for file in $tmpList; do
			ln -s $1/${PROJ_TOP}_common/configs/$file $1/prjConfigs
		done
	fi

}


preload_config(){
	echo -e "\033[1;32m* Buildroot configuring...\033[0m"
	if [ ! -f $1/$2_defconfig ]; then
		echo "Copy default config from $3/prjConfig/$2_defconfig"
		cp $3/prjConfigs/$2_defconfig $1/$2_defconfig
	fi
	make $2_defconfig
}

#
#	proj_config()
#	$1: Build project
#
proj_config(){
	echo -e "\033[1;32m* Buildroot menuconfig\033[0m"
	make defconfig O=./output_$1 BR2_DEFCONFIG=project/prjConfigs/$1_defconfig
	make menuconfig O=./output_$1
	make savedefconfig O=./output_$1 BR2_DEFCONFIG=project/prjConfigs/$1_defconfig 
	#svn diff project/$1/prjConfigs/$1_defconfig
}

init_build(){
	echo -e "\033[46mBuilding Firmware upgrade image\033[0m"
	echo -n "Building project : "
	echo -e "\033[1;32m$1\033[0m"
	echo "Building time : `date -R`($BUILD_START_TIMESTAMP)"
	echo "Building user : $USER"
	echo "Building host : $HOSTNAME"
	echo "Current  path : $PWD"
}

#
#	proj_build()
#
#	$1: Home directory
#	$2: Build project
# 
proj_build(){
	[ ! -d $1/output_$2 ] && mkdir -p $1/output_$2
	#cp -a $1/project/prjConfigs/$2_defconfig $1/output_$2/.config
	#cp -a $1/project/prjConfigs/$2_defconfig ./.config

	echo -e "\033[1;32m* Buildroot building...\033[0m"
	BUILD_START_TIMESTAMP=`date +%s`

	make defconfig BR2_DEFCONFIG=$1/project/prjConfigs/$2_defconfig O=$1/output_$2 || exit 1
	make v=1 O=$1/output_$2 || exit 1

	BUILD_END_TIMESTAMP=`date +%s`
	echo "Total : $((BUILD_END_TIMESTAMP-BUILD_START_TIMESTAMP)) secs"
}

proj_clean(){
	echo -e "\033[1;32m* Buildroot Clean...\033[0m"
	make clean
	rm -rf output_$1
	rm -rf output
}

proj_build_pkg(){
	echo -e "\033[1;32m* Buildroot package building...\033[0m"
	[ ! -d ./output_$2 ] && mkdir -p ./output_$2
	BUILD_START_TIMESTAMP=`date +%s`

	make v=1 $1 O=./output_$2 || exit 1

	BUILD_END_TIMESTAMP=`date +%s`
	echo "Total : $((BUILD_END_TIMESTAMP-BUILD_START_TIMESTAMP)) secs"

}

proj_genfw(){

	if [ "$1" == "korra_spi" ]; then
		IMGPATH=./output_$1/images
		RIMGPATH=./output_korra_rescue/images
		FIMGPATH=./output_korra_fwupg/images
		echo "---$IMGPATH---"
		RESCUEIMG=
		if [ -d $RIMGPATH ]; then
			cp $RIMGPATH/uImage $IMGPATH/rescue.knl || exit_build "Rescue image non-exsit"
			cp $RIMGPATH/rtd-119x-nas-rescue.dtb $IMGPATH/rescue.dtb || exit_build "Rescue dtb non-exist"
			RESCUEIMG="rescue.knl rescue.dtb"
		else
			echo "Warning: Rescue ouput folder is not found!!!"
		fi

		if [ -d $FIMGPATH ]; then
			cp $FIMGPATH/uImage $IMGPATH/fwupg.knl || exit_build "Fwupg image non-exsit"
			cp $FIMGPATH/rtd-119x-nas-rescue.dtb $IMGPATH/fwupg.dtb || exit_build "Fwupg dtb non-exist"
			FWUPGIMG="fwupg.knl fwupg.dtb"
		else
			echo "Warning: FWupg ouput folder is not found!!!"
			exit
		fi
		
		if [ -d $IMGPATH ]; then
			FWVER=`cat ./output_$1/target/etc/version`
			cp ./output_$1/target/etc/version $IMGPATH/fw.version
			cp ./project/$1/updatefw $IMGPATH/updatefw
			cp ./project/$1/configs/bluecore.audio $IMGPATH/bluecore.audio
			mkdir -p $IMGPATH/mcufw
			cp -a ./project/prjPackages/mcu_daemon/firmware/*.bin $IMGPATH/mcufw/
			mkdir -p $IMGPATH/asmfw
			cp -a ./project/prjPackages/asmupdate/firmware/*.bin $IMGPATH/asmfw/
			mkdir -p $IMGPATH/bootcodefw
			cp -a $IMGPATH/bootcode.img $IMGPATH/bootcodefw/
			cp $IMGPATH/uImage $IMGPATH/normal.knl  || exit 1
			cp $IMGPATH/rtd-119x-pmx.dtb $IMGPATH/normal.dtb  || exit 1
			cp $IMGPATH/bootcode_*.bin $IMGPATH/loader.bin  || exit 1
			FWIMGS="updatefw fw.version rootfs.tar.gz normal.knl normal.dtb loader.bin bootcodefw mcufw asmfw bin bluecore.audio"
			pushd $IMGPATH
				[ -f updatefw ] && md5sum updatefw > fw.md5
				[ -f fw.version ] && md5sum fw.version >> fw.md5
				[ -f rootfs.tar.gz ] && md5sum rootfs.tar.gz >> fw.md5
				[ -f lite_drv.tar ] && md5sum lite_drv.tar >> fw.md5
				[ -f lite_normal.knl ] && md5sum lite_normal.knl >> fw.md5
				[ -f lite_normal.dtb ] && md5sum lite_normal.dtb >> fw.md5
				[ -f lite_loader.bin ] && md5sum lite_loader.bin >> fw.md5
				[ -f normal.knl ] && md5sum normal.knl >> fw.md5
				[ -f normal.dtb ] && md5sum normal.dtb >> fw.md5
				[ -f rescue.knl ] && md5sum rescue.knl >> fw.md5
				[ -f rescue.dtb ] && md5sum rescue.dtb >> fw.md5
				[ -f fwupg.knl ] && md5sum fwupg.knl >> fw.md5
				[ -f fwupg.dtb ] && md5sum fwupg.dtb >> fw.md5
				[ -f loader.bin ] && md5sum loader.bin >> fw.md5
				[ -f bluecore.audio ] && md5sum bluecore.audio >> fw.md5
				[ -f bootcodefw/bootcode.img ] && md5sum bootcodefw/bootcode.img >> fw.md5
				md5sum mcufw/* >> fw.md5
				md5sum asmfw/* >> fw.md5
				md5sum bin/* >> fw.md5
				tar cvf ./MyPassportWirelessGen2_${FWVER}.bin $FWIMGS $RESCUEIMG $FWUPGIMG fw.md5
			popd
			tree $IMGPATH
		else
			echo "No output for project $1, Please build first"
		fi
	fi

	if [ "$1" == "korra_rescue" ]; then
		IMGPATH=./output_$1/images
		FWVER=`cat ./output_$1/target/etc/version`
		echo "---$IMGPATH---"
		if [ -d $IMGPATH ]; then
			cp $IMGPATH/uImage $IMGPATH/boot.img  || exit 1
			cp $IMGPATH/rtd-119x-nas-rescue.dtb $IMGPATH/boot.inf  || exit 1
			mkdir -p $IMGPATH/recovery-$FWVER
			mv $IMGPATH/boot.inf $IMGPATH/recovery-$FWVER/  || exit 1
			mv $IMGPATH/boot.img $IMGPATH/recovery-$FWVER/  || exit 1
			tree $IMGPATH
		else
			echo "No output for project $1, Please build first"
		fi
	fi

	if [ "$1" == "korra_fwupg" ]; then
		IMGPATH=./output_$1/images
		FWVER=`cat ./output_$1/target/etc/version`
		echo "---$IMGPATH---"
		if [ -d $IMGPATH ]; then
			cp $IMGPATH/uImage $IMGPATH/fwupg.img  || exit 1
			cp $IMGPATH/rtd-119x-nas-rescue.dtb $IMGPATH/fwupg.inf  || exit 1
			mkdir -p $IMGPATH/fwupg-$FWVER
			mv $IMGPATH/fwupg.inf $IMGPATH/fwupg-$FWVER/  || exit 1
			mv $IMGPATH/fwupg.img $IMGPATH/fwupg-$FWVER/  || exit 1
			tree $IMGPATH
		else
			echo "No output for project $1, Please build first"
		fi
	fi

}

HOME_DIR=`pwd`
PROJ_DIR=$HOME_DIR/project
CFGS_DIR=$HOME_DIR/configs

[ $# -lt 2 ] && usage && exit 1

BUILD_PROJ=$1
BUILD_TARGET=$2

[ $BUILD_PROJ == "help" ] && usage && exit 0
[ ! -d $HOME_DIR/project/$BUILD_PROJ ] && echo "Project non-exist" && exit 1

TAR_PROJ_PATH=$PROJ_DIR/$BUILD_PROJ

init_build $BUILD_PROJ
init_link $PROJ_DIR $BUILD_PROJ
#preload_config $CFGS_DIR $BUILD_PROJ $TAR_PROJ_PATH

if [ "$2" = "" ]; then
	usage
else
    while [ "$2" != "" ]
    do
        case "$2" in
            config)
                echo "Config $BUILD_PROJ"
                proj_config $BUILD_PROJ
                ;;
            build)
                echo "Build $BUILD_PROJ"
                proj_build $HOME_DIR $BUILD_PROJ
                ;;
            clean)
                echo "Clean $BUILD_PROJ"
                proj_clean $BUILD_PROJ
                remove_link $PROJ_DIR
                ;;
            genfw)
                echo "Gen FW for $BUILD_PROJ"
                proj_genfw $BUILD_PROJ
                ;;
            *)
                echo "Build $BUILD_TARGET for $BUILD_PROJ"
                proj_build_pkg $BUILD_TARGET $BUILD_PROJ
                ;;
        esac
        shift 1
    done
fi



