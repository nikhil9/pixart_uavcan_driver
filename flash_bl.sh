#!/bin/bash

ref_v=$(git show -s --format=%h)

echo 'Compiling bootloader for STM32F3 with' $ref_v

bl_dir='modules/bootloader'

cd $bl_dir

BOARD=com.hex.flow_1.0 make || exit 1

echo '******************************************************'
echo '	BOOTLOADER BUILD SUCCESS!				'
echo '******************************************************'

elf_d='modules/bootloader/build/com.hex.flow_1.0_bl/bin/main.elf'

cd ../..

openocd -f openocd.cfg -c "program $elf_d verify reset exit" || exit 1

echo '******************************************************'
echo '	BOOTLOADER DLASH SUCCESS!				'
echo '******************************************************'




