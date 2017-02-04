
#include "MicroBit.h"
#include "CalliopeDemos.h"

#ifdef CALLIOPE_DEMO_ACCELEROMETER

MicroBit uBit;

int main()
{
  uBit.init();
  //uBit.serial.baud(115200);

  // current pixel coordinates, saved
  int x = -1, y = -1;
  uint16_t oldgesture = 0;
  while (1)
  {
    int dx = uBit.accelerometer.getX();
    int dy = uBit.accelerometer.getY();
    // uBit.serial.printf("dx=%d, dy=%d\r\n", dx, dy);

    // scale the values ([-1024:-1024] => [0:4])
    int nx = (dx + 1024) * 5 / 2048;
    int ny = (dy + 1024) * 5 / 2048;

    // only change the pixel if the coordinates have changed
    if (nx != x || ny != y)
    {
      x = nx;
      y = ny;
      uBit.display.image.clear();
      uBit.display.image.setPixelValue(x, y, 255);
      //uBit.serial.printf(" x=%d,  y=%d\r\n", nx, ny);
    }
    uint16_t gesture = uBit.accelerometer.getGesture();
    if(gesture != oldgesture) {
      oldgesture = gesture;
      switch (gesture)
      {
      case MICROBIT_ACCELEROMETER_EVT_TILT_UP:
        uBit.display.printChar('U');
        break;
      case MICROBIT_ACCELEROMETER_EVT_TILT_DOWN:
        uBit.display.printChar('D');
        break;
      case MICROBIT_ACCELEROMETER_EVT_TILT_LEFT:
        uBit.display.printChar('L');
        break;
      case MICROBIT_ACCELEROMETER_EVT_TILT_RIGHT:
        uBit.display.printChar('R');
        break;
      case MICROBIT_ACCELEROMETER_EVT_FACE_UP:
        uBit.display.printChar('+');
        break;
      case MICROBIT_ACCELEROMETER_EVT_FACE_DOWN:
        uBit.display.printChar('-');
        break;
      case MICROBIT_ACCELEROMETER_EVT_FREEFALL:
        uBit.display.printChar('F');
        break;
#if defined(MICROBIT_ACCELEROMETER_EVT_2G)
      case MICROBIT_ACCELEROMETER_EVT_2G:
        uBit.display.printChar('2');
        break;
#endif
      case MICROBIT_ACCELEROMETER_EVT_6G:
        uBit.display.printChar('6');
        break;
      case MICROBIT_ACCELEROMETER_EVT_8G:
        uBit.display.printChar('8');
        break;
      case MICROBIT_ACCELEROMETER_EVT_SHAKE:
        uBit.display.printChar('S');
        break;
      default:
        break;
      }
      if(gesture) uBit.sleep(2000);
    }
    uBit.sleep(100);
  }
}

#endif
