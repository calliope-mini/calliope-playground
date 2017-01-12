/*
The MIT License (MIT)

Copyright (c) 2016 British Broadcasting Corporation.
This software is provided by Lancaster University by arrangement with the BBC.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "MicroBit.h"
#include "CalliopeDemos.h"
#include "pinmap.h"

#ifdef CALLIOPE_ANALOG_DEMO

// this is a test (rev 0.3) whether we can receive data on the UART
int main() {
    RawSerial pc(USBTX, USBRX);

    analogin_t ain0, ain1;

    pc.baud(115200);
    pc.puts("press Enter ...\r\n");

    // try to set an analog value (output)
    pwmout_t pwm1, pwm2;
    pwmout_init(&pwm1, EXT_RX);
    pwmout_init(&pwm2, EXT_TX);
    pwmout_write(&pwm1, 1.0);
    pwmout_write(&pwm2, 1.0);
    for (int i = 0; i < 100; i += 10) {
        pc.printf("%d 0.%d\r\n", i, (int) (i / 100.0) * 10);
        pwmout_write(&pwm1, i / 100.0);
        pwmout_write(&pwm2, i / 100.0);
        wait_ms(1);
    }
    pwmout_free(&pwm1);
    pwmout_free(&pwm2);

    // try to read analog value (input)
    analogin_init(&ain0, EXT_RX);
    analogin_init(&ain1, EXT_TX);
    while (true) {
        float v = analogin_read(&ain0);
        printf("analog: %d\r\n", (int) (v*100.0));
        wait_ms(100);
    }
}

#endif
