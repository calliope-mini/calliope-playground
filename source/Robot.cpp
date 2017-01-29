#include "CalliopeDemos.h"

#include "MicroBit.h"
#include "CalliopeRGB.h" 
#include "CalliopeSoundMotor.h" 

#ifdef CALLIOPE_DEMO_ROBOT

MicroBit uBit;
MicroBitDisplay display;

int main() {
    // Initialise the micro:bit runtime.
    uBit.init();
    while (1) {
        for (int i = 40; i < 500; i++) {
            uBit.soundmotor.motorBOn(i);
            uBit.soundmotor.motorAOn(i);
            uBit.sleep(100);
        }
        uBit.soundmotor.motorBOff();
        uBit.soundmotor.motorAOff();

        uBit.soundmotor.motorAOn(80);
        uBit.sleep(300);
        uBit.soundmotor.motorAOff();

        uBit.soundmotor.motorBOn(80);
        uBit.sleep(300);
        uBit.soundmotor.motorBOff();

        uBit.soundmotor.motorBOn(80);
        uBit.soundmotor.motorAOn(80);
        uBit.sleep(300);
        uBit.soundmotor.motorBOff();
        uBit.soundmotor.motorAOff();

        uBit.sleep(2000);
    }
}

#endif
