# xiao-ble-localizer
BLE-based indoor localization on the Seeed Xiao BLE Sense using the Zephyr RTOS

Currently this is the sample observer bluetooth program + custom timer based heartbeat lib for MCU. 

**RSSI** will be the main way for getting distance. Later we can have 3 beacons from `samples/bluetooth/beacon` sample code and then one observer doing trilateration/localization logic 

build via:

    west build -p always -b xiao_ble/nrf52840/sense

flash via:

    west flash -r uf2

To see the serial port output for bluetooth ( on linux minicom ):

    minicom -D /dev/ttyACM0 -b 115200
