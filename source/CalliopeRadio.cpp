
#include "CalliopeDemos.h"
#include "MicroBit.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"


#ifdef CALLIOPE_DEMO_RADIO

MicroBit uBit;


void buttonA(MicroBitEvent event) {
    uBit.serial.send("START\r\n");
    uBit.radio.datagram.send("S");
}

void buttonB(MicroBitEvent event) {
    uBit.serial.send("START 1\r\n");
    uBit.radio.datagram.send("H1");
}

void buttonB1(MicroBitEvent event) {
    uBit.serial.send("RANDOM SEED\r\n");
    uBit.radio.datagram.send(uBit.random(100) > 20 ? "1" : "0");
}

void buttonAB(MicroBitEvent event) {
    uBit.serial.send("END\r\n");
    uBit.radio.datagram.send("E");
}


void onData(MicroBitEvent event) {
    PacketBuffer packet = uBit.radio.datagram.recv();
    uBit.serial.send("RECEIVED\r\n");
    uBit.serial.send(packet);
    uBit.display.print(packet);
}

int main() {
    uBit.init();

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, buttonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, buttonB);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_LONG_CLICK, buttonB1);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_CLICK, buttonAB);

    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onData);

    if(uBit.radio.enable() == MICROBIT_OK) uBit.display.scroll("RDY");
    uBit.radio.setGroup(227);

    while(true) uBit.sleep(100);
}

#endif
