#include "CalliopeDemos.h"

#include "MicroBit.h"
#include "CalliopeRGB.h" 
#include "CalliopeSoundMotor.h" 

#ifdef CALLIOPE_DEMO_SOUNDMOTORRGB

MicroBit uBit;
MicroBitDisplay display;

int main() {
    // Initialise the micro:bit runtime.
    uBit.init();
    display.scroll("WELCOME");
    uBit.serial.baud(115200);
    uBit.serial.send("DEMO\n\r");

    uBit.rgb.setColour(0, 0xff, 0xff, 0);

    while (1) {
        //motors A and B on for 12 seconds, blink red and green
        uBit.soundmotor.MotorB_On(80);
        uBit.soundmotor.MotorA_On(80);

        for (int i = 0; i < 6; i++) {
            uBit.rgb.setColour(0, 100, 0, 0);
            uBit.sleep(1000);
            uBit.rgb.setColour(100, 0, 0, 0);
            uBit.sleep(1000);
        }

        //all off, short delay
        uBit.soundmotor.MotorB_Off();
        uBit.soundmotor.MotorA_Off();
        uBit.rgb.setColour(0, 0, 0, 0);
        uBit.sleep(2000);

        //sound on for 6 seconds in silent mode, blink blue and white
        uBit.soundmotor.Sound_Set_Silent_Mode(true);
        uBit.soundmotor.Sound_On(50);


        for (int i = 0; i < 3; i++) {
            uBit.rgb.setColour(0, 0, 100, 0);
            uBit.sleep(1000);
            uBit.rgb.setColour(100, 100, 100, 0);
            uBit.sleep(1000);
        }

        //sound on for 6 seconds without silent mode, blink blue and white
        uBit.soundmotor.Sound_Set_Silent_Mode(false);
        uBit.soundmotor.Sound_On(100);

        for (int i = 0; i < 3; i++) {
            uBit.rgb.setColour(0, 0, 100, 0);
            uBit.sleep(1000);
            uBit.rgb.setColour(100, 100, 100, 0);
            uBit.sleep(1000);
        }

        //all off, short delay
        uBit.soundmotor.Sound_Off();
        uBit.rgb.setColour(0, 0, 0, 0);
        uBit.sleep(2000);
    }
} 

#endif
