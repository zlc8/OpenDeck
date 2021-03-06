#!/bin/bash

echo "Please select the board for which you want to update firmware:"

echo "1 - Official OpenDeck board"
echo "2 - Arduino Mega"
echo "3 - Arduino Uno"
echo "4 - Arduino Leonardo"
echo "5 - Arduino Pro Micro"
echo "6 - Teensy++ 2.0"

read board

if [ $board == 1 ]
then
    ../bin/dfu/hid_bootloader_loader_mac atmega32u4 ../bin/compiled/opendeck/fw_opendeck.hex
elif [ $board == 2 ]
then
    ../bin/dfu/hid_bootloader_loader_mac atmega2560 ../bin/compiled/arduino+teensy/fw/fw_mega.hex
elif [ $board == 3 ]
then
    ../bin/dfu/hid_bootloader_loader_mac atmega328p ../bin/compiled/arduino+teensy/fw/fw_uno.hex
elif [ $board == 4 ]
then
    ../bin/dfu/hid_bootloader_loader_mac atmega32u4 ../bin/compiled/arduino+teensy/fw/fw_leonardo.hex
elif [ $board == 5 ]
then
    ../bin/dfu/hid_bootloader_loader_mac atmega32u4 ../bin/compiled/arduino+teensy/fw/fw_pro_micro.hex
elif [ $board == 6 ]
then
    ../bin/dfu/hid_bootloader_loader_mac at90usb1286 ../bin/compiled/arduino+teensy/fw/fw_teensy2pp.hex
else
    echo "Incorrect board number selected."
fi