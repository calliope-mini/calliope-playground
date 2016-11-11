#include "CalliopeDemos.h"

#include "MicroBit.h"
#include "CalliopeRGB.h" 
#include "CalliopeSoundMotor.h" 

#ifdef CALLIOPE_TEST_MOTORS_DUAL

MicroBit uBit;

int main() {

    // Initialise the micro:bit runtime.
    uBit.init();

    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.serial.baud(115200);
    uBit.serial.send("MOTORS\n\r");

    uBit.display.print("A");
    uBit.soundmotor.motorAOn(100);
    uBit.sleep(1000);
    uBit.soundmotor.motorAOff();
    uBit.display.print("B");
    uBit.soundmotor.motorBOn(50);
    uBit.sleep(1000);
    uBit.soundmotor.motorBOff();
    uBit.display.print("A");
    uBit.soundmotor.motorAOn(100);
    uBit.sleep(1500);
    uBit.soundmotor.motorAOff();

    uBit.serial.printf("A+B 100%%\r\n");
    uBit.soundmotor.motorAOn(100);
    uBit.soundmotor.motorBOn(100);
    uBit.sleep(5000);

    uBit.serial.printf("A+B same speed\r\n");
    for (uint8_t i = 10; i <= 100; i += 10) {
        uBit.serial.printf("A+B - %d \r\n", i);
        uBit.soundmotor.motorAOn(i);
        uBit.soundmotor.motorBOn(i);
        uBit.sleep(1000);
    }

    uBit.serial.send("Motor A on\r\n");
    uBit.rgb.setColour(255, 0, 0, 0);
    uBit.soundmotor.motorAOn(100);
    uBit.soundmotor.motorBOff();
    uBit.sleep(5000);

    uBit.serial.send("Motor B on\r\n");
    uBit.rgb.setColour(255, 0, 0, 0);
    uBit.soundmotor.motorBOn(100);
    uBit.soundmotor.motorAOff();
    uBit.sleep(5000);

    uBit.serial.printf("A speedup (1)\r\n");
    for (uint8_t i = 10; i <= 100; i += 10) {
        uBit.serial.printf("A - %d \r\n", i);
        uBit.soundmotor.motorAOn(i);
        uBit.soundmotor.motorBOff();
        uBit.sleep(1000);
    }
    uBit.soundmotor.motorAOff();

    uBit.serial.printf("B speedup (1)\r\n");
    for (uint8_t i = 10; i <= 100; i += 10) {
        uBit.serial.printf("B - %d \r\n", i);
        uBit.soundmotor.motorBOn(i);
        uBit.soundmotor.motorAOff();
        uBit.sleep(1000);
    }
    uBit.soundmotor.motorBOff();

    // from here on it goes wrong! NO MORE!
    uBit.serial.printf("A speedup (2)\r\n");
    for (uint8_t i = 10; i <= 100; i += 10) {
        uBit.serial.printf("A - %d \r\n", i);
        uBit.soundmotor.motorAOn(i);
        uBit.sleep(1000);
    }
    uBit.soundmotor.motorAOff();

    uBit.serial.printf("B speedup (2)\r\n");
    for (uint8_t i = 10; i <= 100; i += 10) {
        uBit.serial.printf("B - %d \r\n", i);
        uBit.soundmotor.motorBOn(i);
        uBit.sleep(1000);
    }
    uBit.soundmotor.motorBOff();

    uBit.serial.send("A - off, B - 100\r\n");
    uBit.soundmotor.motorAOff();
    uBit.soundmotor.motorBOn(100);
    uBit.sleep(10000);

    uBit.serial.send("A - 100, B - off\r\n");
    uBit.soundmotor.motorAOn(100);
    uBit.soundmotor.motorBOff();
    uBit.sleep(10000);

    uBit.serial.send("A - 100, B - 100\r\n");
    uBit.soundmotor.motorAOn(100);
    uBit.soundmotor.motorBOn(100);
    uBit.sleep(10000);

    uBit.serial.send("A - 80, B - 80\r\n");
    uBit.soundmotor.motorAOn(80);
    uBit.soundmotor.motorBOn(80);
    uBit.sleep(10000);

    uBit.serial.send("A - 100, B - 80\r\n");
    uBit.soundmotor.motorAOn(100);
    uBit.soundmotor.motorBOn(80);
    uBit.sleep(10000);

    uBit.soundmotor.motorAOff();
    uBit.soundmotor.motorBOff();

    while (1) uBit.sleep(100);
}

#endif
