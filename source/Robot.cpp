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
            uBit.soundmotor.MotorB_On(i);
            uBit.soundmotor.MotorA_On(i);
            uBit.sleep(100);
        }
        uBit.soundmotor.MotorB_Off();
        uBit.soundmotor.MotorA_Off();

        uBit.soundmotor.MotorA_On(80);
        uBit.sleep(300);
        uBit.soundmotor.MotorA_Off();

        uBit.soundmotor.MotorB_On(80);
        uBit.sleep(300);
        uBit.soundmotor.MotorB_Off();

        uBit.soundmotor.MotorB_On(80);
        uBit.soundmotor.MotorA_On(80);
        uBit.sleep(300);
        uBit.soundmotor.MotorB_Off();
        uBit.soundmotor.MotorA_Off();

        uBit.sleep(2000);
    }
}

#endif
