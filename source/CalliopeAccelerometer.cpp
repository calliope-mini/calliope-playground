
#include "MicroBit.h"
#include "CalliopeDemos.h"

#ifdef CALLIOPE_DEMO_ACCELEROMETER

MicroBit uBit;

int main()
{
    uBit.init();
    uBit.accelerometer.configure();

    // current pixel coordinates, saved
    int x = -1, y = -1;
    while(1)
    {
      int dx = uBit.accelerometer.getX();
      int dy = uBit.accelerometer.getY();

      // scale the values ([-1024:-1024] => [0:4])
	    int nx = (dx + 1024) * 5 / 2048;
	    int ny = (dy + 1024) * 5 / 2048;

      // only change the pixel if the coordinates have changed
      if(nx != x || ny != y) {
        x = nx;
        y = ny;
        uBit.display.image.clear();
        uBit.display.image.setPixelValue(y, x, 255);
      }
    }
}

#endif
