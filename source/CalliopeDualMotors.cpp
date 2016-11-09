#include "CalliopeDemos.h"

#include "MicroBit.h"
#include "CalliopeRGB.h" 
#include "CalliopeSoundMotor.h" 

#ifdef CALLIOPE_TEST_MOTORS_DUAL

MicroBit uBit;

int main() {
    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.serial.baud(115200);
    uBit.serial.send("MOTORS\n\r");

    uBit.serial.send("A - off, B - 90\r\n");
    uBit.soundmotor.motorBOn(90);
    uBit.soundmotor.motorAOff();
    uBit.sleep(20000);

    uBit.serial.send("A - 90, B - off\r\n");
    uBit.soundmotor.motorBOff();
    uBit.soundmotor.motorAOn(90);
    uBit.sleep(20000);

    uBit.serial.send("A - off, B - 100\r\n");
    uBit.soundmotor.motorBOn(100);
    uBit.soundmotor.motorAOff();
    uBit.sleep(20000);

    uBit.serial.send("A - 100, B - off\r\n");
    uBit.soundmotor.motorBOff();
    uBit.soundmotor.motorAOn(100);
    uBit.sleep(20000);

    uBit.serial.send("A - 100, B - 100\r\n");
    uBit.soundmotor.motorBOn(100);
    uBit.soundmotor.motorAOn(100);
    uBit.sleep(20000);

    uBit.serial.send("A - 30, B - 90\r\n");
    uBit.soundmotor.motorBOn(70);
    uBit.soundmotor.motorAOn(30);
    uBit.sleep(20000);

    uBit.soundmotor.motorAOff();
    uBit.soundmotor.motorBOff();

    while (1) uBit.sleep(100);
}

#endif
