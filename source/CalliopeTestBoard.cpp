#include "CalliopeDemos.h"

#include "MicroBit.h"
#include "CalliopeRGB.h" 
#include "CalliopeSoundMotor.h" 

#ifdef CALLIOPE_TEST_BOARD

MicroBit uBit;
MicroBitImage full(
        "255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n");
MicroBitImage tick("0,0,0,0,0\n0,0,0,0,255\n0,0,0,255,0\n255,0,255,0,0\n0,255,0,0,0\n");


int main() {
    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.serial.baud(115200);
    uBit.serial.send("TEST\r\n");

    uBit.serial.send("display\r\n");
    uBit.display.clear();
    uBit.display.print(full);
    for (int i = 255; i > 0; i--) {
        uBit.display.setBrightness(i);
        uBit.sleep(1);
    }
    for (int i = 0; i < 255; i++) {
        uBit.display.setBrightness(i);
        uBit.sleep(1);
    }

    uBit.serial.send("accelerometer\r\n");
    uBit.display.print("A");
    for (int i = 0; i < 10; i++) {
        uBit.accelerometer.getX();
        uBit.accelerometer.getY();
        uBit.accelerometer.getZ();
    }
    uBit.display.print(tick);
    uBit.sleep(500);

#ifdef TEST_BUTTONS
    uBit.serial.send("buttons\r\n");
    uBit.display.print("A");
    while(!uBit.buttonA.isPressed());
    uBit.serial.send("A");
    uBit.display.print(tick);
    uBit.display.print("B");
    while(!uBit.buttonB.isPressed());
    uBit.serial.send("B");
    uBit.display.print(tick);
    uBit.display.print("0");
    while(!uBit.io.P0.isTouched());
    uBit.serial.send("0");
    uBit.display.print(tick);
    uBit.display.print("1");
    while(!uBit.io.P1.isTouched());
    uBit.serial.send("1");
    uBit.display.print(tick);
    uBit.display.print("2");
    while(!uBit.io.P2.isTouched());
    uBit.serial.send("2");
    uBit.display.print(tick);
    uBit.display.print("3");
    while(!uBit.io.CAL_P22.isTouched());
    uBit.serial.send("3");
    uBit.display.print(tick);
    uBit.display.clear();
#endif

    uBit.serial.send("RGB led\r\n");
    uBit.display.print("R");
    uBit.rgb.off();
    uBit.rgb.setColour(255, 0, 0, 0);
    uBit.sleep(500);
    uBit.rgb.off();
    uBit.rgb.setColour(0, 255, 0, 0);
    uBit.sleep(500);
    uBit.rgb.off();
    uBit.rgb.setColour(0, 0, 255, 0);
    uBit.sleep(500);
    uBit.rgb.off();


    uBit.serial.send("sound\r\n");
    uBit.display.print("S");
    uBit.soundmotor.Sound_Set_Silent_Mode(true);
    uBit.soundmotor.Sound_On(500);
    uBit.sleep(100);
    uBit.soundmotor.Sound_On(2000);
    uBit.sleep(100);
    uBit.soundmotor.Sound_On(3000);
    uBit.sleep(100);
    uBit.soundmotor.Sound_Off();

    uBit.display.clear();
}

#endif
