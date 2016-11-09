#include "CalliopeDemos.h"

#include "MicroBit.h"
#include "CalliopeRGB.h" 
#include "CalliopeSoundMotor.h" 

#ifdef CALLIOPE_TEST_MOTORS_SINGLE

MicroBit uBit;


int main() {
    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.serial.baud(115200);
    uBit.serial.send("MOTORS\n\r");

    uBit.serial.send("Single Motor 50\r\n");
    uBit.soundmotor.motorOn(50);
    uBit.sleep(10000);

    uBit.serial.send("Single Motor 100\r\n");
    uBit.soundmotor.motorOn(100);
    uBit.sleep(10000);

    uBit.serial.send("Single Motor -50\r\n");
    uBit.soundmotor.motorOn(-50);
    uBit.sleep(10000);

    uBit.serial.send("Single Motor -100\r\n");
    uBit.soundmotor.motorOn(-50);
    uBit.sleep(10000);

    uBit.soundmotor.motorAOff();
    uBit.soundmotor.motorBOff();

    while (1) uBit.sleep(100);
}

#endif
