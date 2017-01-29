#include "CalliopeDemos.h"

#include "MicroBit.h"
#include "CalliopeRGB.h" 
#include "CalliopeSoundMotor.h" 

#ifdef CALLIOPE_TEST_BOARD

MicroBit uBit;
MicroBitImage full(
        "255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n255,255,255,255,255\n");
MicroBitImage tick("0,0,0,0,0\n0,0,0,0,255\n0,0,0,255,0\n255,0,255,0,0\n0,255,0,0,0\n");


#ifdef TEST_BUTTONS
void onButtonA(MicroBitEvent event) { (void)event; uBit.display.print("A"); }
void onButtonB(MicroBitEvent event) { (void)event; uBit.display.print("B"); }
void onButtonAB(MicroBitEvent event) { (void)event; uBit.display.print("A+B"); }
void onButton0(MicroBitEvent event) { (void)event; uBit.display.print("0"); }
void onButton1(MicroBitEvent event) { (void)event; uBit.display.print("1"); }
void onButton2(MicroBitEvent event) { (void)event; uBit.display.print("2"); }
void onButton3(MicroBitEvent event) { (void)event; uBit.display.print("3"); }
#endif

#ifdef TEST_GESTURES
void onShake(MicroBitEvent event) { (void)event; uBit.display.print("S"); }
void onFaceUp(MicroBitEvent event) { (void)event; uBit.display.print("+"); }
void onFaceDown(MicroBitEvent event) { (void)event; uBit.display.print("-"); }
void onTiltUp(MicroBitEvent event) { (void)event; uBit.display.print("U"); }
void onTiltDown(MicroBitEvent event) { (void)event; uBit.display.print("D"); }
void onTiltLeft(MicroBitEvent event) { (void)event; uBit.display.print("L"); }
void onTiltRight(MicroBitEvent event) { (void)event; uBit.display.print("R"); }
#endif

int main() {
    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.serial.baud(115200);
    uBit.serial.send("TEST\r\n");

    uBit.serial.send("display\r\n");
    uBit.display.clear();
    uBit.display.print(full);
    for (int i = 255; i > 0; i-=2) {
        uBit.display.setBrightness(i);
        uBit.sleep(3);
    }
    uBit.sleep(3);
    for (int i = 0; i < 255; i+=2) {
        uBit.display.setBrightness(i);
        uBit.sleep(3);
    }

    uBit.serial.send("accelerometer\r\n");
    uBit.display.print("A");
    for (int i = 0; i < 10; i++) {
        uBit.accelerometer.getX();
        uBit.accelerometer.getY();
        uBit.accelerometer.getZ();
    }
    uBit.display.print(tick);
    uBit.sleep(100);

    uBit.serial.send("RGB led\r\n");
    uBit.display.print("R");
    uBit.rgb.off();
    uBit.rgb.setColour(255, 0, 0, 0);
    uBit.sleep(100);
    uBit.rgb.off();
    uBit.rgb.setColour(0, 255, 0, 0);
    uBit.sleep(100);
    uBit.rgb.off();
    uBit.rgb.setColour(0, 0, 255, 0);
    uBit.sleep(100);
    uBit.rgb.off();


    uBit.serial.send("sound\r\n");
    uBit.display.print("S");
    uBit.soundmotor.setSoundSilentMode(true);
    uBit.soundmotor.soundOn(500);
    uBit.sleep(100);
    uBit.soundmotor.soundOn(2000);
    uBit.sleep(100);
    uBit.soundmotor.soundOn(3000);
    uBit.sleep(100);
    uBit.soundmotor.soundOff();

    uBit.display.clear();

#ifdef TEST_BUTTONS
    // we need to trigger touch sensing
    uBit.io.P12.isTouched(); // this is touch corner P0 on Calliope mini
    uBit.io.P0.isTouched();  // this is touch corner P1 on Calliope mini
    uBit.io.P1.isTouched();  // this is touch corner P2 on Calliope mini
    uBit.io.P16.isTouched(); // this is touch corner P3 on Calliope mini

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_CLICK, onButtonAB);
    uBit.messageBus.listen(MICROBIT_ID_IO_P12, MICROBIT_EVT_ANY, onButton0);
    uBit.messageBus.listen(MICROBIT_ID_IO_P0, MICROBIT_EVT_ANY, onButton1);
    uBit.messageBus.listen(MICROBIT_ID_IO_P1, MICROBIT_EVT_ANY, onButton2);
    uBit.messageBus.listen(MICROBIT_ID_IO_P16, MICROBIT_EVT_ANY, onButton3);
#endif

#ifdef TEST_GESTURES
    uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_SHAKE, onShake);
    uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_FACE_UP, onFaceUp);
    uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_FACE_DOWN, onFaceDown);
    uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_TILT_UP, onTiltUp);
    uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_TILT_DOWN, onTiltDown);
    uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_TILT_LEFT, onTiltLeft);
    uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_TILT_RIGHT, onTiltRight);
#endif

    while(1) uBit.sleep(100);
}
#endif
