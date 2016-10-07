
#include "CalliopeDemos.h"
#include "MicroBit.h"

#ifdef CALLIOPE_DEMO_RGB

MicroBit uBit;

int main() {
    uBit.init();
    uBit.serial.baud(115200);
    uBit.serial.send("RGB DEMO\n\r");

    uBit.display.scroll("RED");
    uBit.serial.send("RED\n\r");
    uBit.rgb.Set_Color(0xff, 0x00, 0x00, 0);
    uBit.display.scroll("GREEN");
    uBit.serial.send("GREEN\n\r");
    uBit.rgb.Set_Color(0x00, 0xff, 0x00, 0);
    uBit.display.scroll("BLUE");
    uBit.serial.send("BLUE\n\r");
    uBit.rgb.Set_Color(0x00, 0x00, 0xff, 0);
    uBit.display.scroll("OFF");
    uBit.serial.send("OFF\n\r");
    uBit.rgb.Set_Color(0xff, 0xff, 0xff, 0);
} 

#endif