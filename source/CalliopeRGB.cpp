
#include "CalliopeDemos.h"
#include "MicroBit.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"


#ifdef CALLIOPE_DEMO_RGB

MicroBit uBit;

int main() {
    uBit.init();

    uBit.rgb.setColour(0xff, 0x00, 0x00, 0x00);

    uBit.sleep(1000);

    uBit.rgb.setColour(0x00, 0xff, 0x00, 0x00);

    uBit.sleep(1000);

    uBit.rgb.setColour(0x00, 0x00, 0xff, 0x00);

    uBit.sleep(1000);

    const uint8_t PIN = P0_18;
    const uint32_t CONST_BIT = 1UL << PIN;

    NRF_GPIO->OUTCLR = (CONST_BIT);
    nrf_delay_us(50);
    
    uint8_t GRBW[4] = { 0xff, 0x00, 0x00, 0x00 };
    
    //send bytes
    for (uint8_t i=0; i<4; i++)
    {
        for(int8_t j=7; j>-1; j--) 
        {
            if (GRBW[i] & (1 << j)) 
            {
                NRF_GPIO->OUTSET = (CONST_BIT);
                __ASM volatile (
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                );
                NRF_GPIO->OUTCLR = (CONST_BIT);
            }
            else 
            {
                 NRF_GPIO->OUTSET = (CONST_BIT);
                __ASM volatile (
                    "NOP\n\t"
                );
                NRF_GPIO->OUTCLR = (CONST_BIT);
                __ASM volatile (
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                    "NOP\n\t"
                );

            }
        }
    }

} 

#endif
