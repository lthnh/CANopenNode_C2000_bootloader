#!/bin/sh

mkdir -p configs/generated
mkdir -p /home/thomas/workspace_ccstheia
mkdir -p artifact
touch ./configs/generated/autoconf.h
/home/thomas/ti/ccs2100/ccs/eclipse/ccs-server-cli.sh -noSplash -workspace '/home/thomas/workspace_ccstheia' -application 'projectImport' -ccs.location .

configNames=$(find configs/ -type f -name "*_defconfig")
for configName in ${configNames}
do
    name=$(basename $configName)
    echo "***********************************************************"
    echo "Building for $name"
    echo "***********************************************************"
    make defconfig CONF=$name
    /home/thomas/ti/ccs2100/ccs/eclipse/ccs-server-cli.sh -noSplash -workspace '/home/thomas/workspace_ccstheia' -application 'projectBuild' -ccs.projects 'CANopenNode_bootloader' -ccs.autoImport
    mkdir -p artifact/$name
    cp Debug/CANopenNode_bootloader.* artifact/$name
    cp configs/$name artifact/$name/$name
done
