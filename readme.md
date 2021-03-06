####  UAVCAN Firmware for pixart + STM32F3 board

**Dependencies**

for python3

```bash
pip3 install uavcan crcmod
```
for python2.7

```bash
pip2 install uavcan crcmod
```

* Download arm-none-eabi-gcc 6.3.1 and add it to the PATH and restart the system

* Clone the repo and update the submodules recursively


**Bootloader**

Connect the board with ST Link and execute flash_bl.sh in terminal. The script will build the bootloader and flash it to the board.


```bash
./flash_bl.sh
```


**Firmware**


Execute `build_firmware.sh` to build the firmware

```bash
./build_firmware.sh
```

The binary generated is located at `build/com.hex.flow_1.0/pixart_uavcan_driver-crc.bin`

Flash this binary using `uavcan_gui_tool`

Raw flow data and qaulity is being broadcasted with msg type `uavcan.equipment.optic_flow.OpticFlow`


