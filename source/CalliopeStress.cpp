#include "CalliopeDemos.h"

#include "MicroBit.h"

#ifdef CALLIOPE_TEST_BOARD_STRESS

MicroBit uBit;
MicroBitImage full(
        "255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n");

int main() {

    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.serial.baud(115200);
    uBit.serial.send("TEST\r\n");

    uBit.serial.send("display\r\n");
    uBit.display.clear();
    uBit.display.print(full);
    uBit.display.setBrightness(255);

    uBit.soundmotor.motorOn(100);
    uBit.rgb.setColour(255,255,255,0);

    int i = 0;
    for(;;) if(++i % 1000000 == 0) printf("MCU: %dºC\r\n", uBit.thermometer.getTemperature());;
    while(true) {
//        uBit.accelerometer.getX();
//        uBit.rgb.off();
//        uBit.rgb.on();
//
    }
}
#endif
