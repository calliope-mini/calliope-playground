#include "CalliopeDemos.h"

#include "MicroBit.h"

#ifdef CALLIOPE_TEST_BOARD_STRESS


MicroBit uBit;
MicroBitImage full(
"255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n");

// we use events abd the 'connected' variable to keep track of the status of the Bluetooth connection
void onConnected(MicroBitEvent) {
    uBit.display.print("C");
    uBit.sleep(1000);
    uBit.display.print(full);
}

void onDisconnected(MicroBitEvent) {
    uBit.display.print("D");
    uBit.sleep(1000);
    uBit.display.print(full);

}

int main() {

    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.serial.baud(115200);
    uBit.serial.send("TEST\r\n");

    uBit.serial.send("display\r\n");
    uBit.display.clear();
    uBit.display.print(full);
    uBit.display.setBrightness(255);

    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, onDisconnected);

    new MicroBitButtonService(*uBit.ble);
    new MicroBitTemperatureService(*uBit.ble, uBit.thermometer);

    uBit.soundmotor.motorOn(100);
    uBit.rgb.setColour(255, 255, 255, 0);

    int i = 0;
    for(;;) if(++i % 1000000 == 0) printf("MCU: %dºC\r\n", uBit.thermometer.getTemperature());
}

#endif
