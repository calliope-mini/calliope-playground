# calliope-playground
Examples for Calliope-MINI functions.

## How to debug on board

* prerequisites: yotta, arm-gcc, openocd, cgdb
* create a file called `gdbinit` in your project dir:
    ```
    target extended-remote localhost:3333
    monitor reset halt
    ```
* The compile step may fail with `error: r7 cannot be used in asm here`, then add this file: `yotta_modules/nrf51-sdk/source/override.cmake`, which contains only this single line: 
    ```
    add_definitions(-fomit-frame-pointer)
    ```
* compile your code 
    ```
    yt build --debug-build
    ```
* start openocd: 
    ```
    openocd -f $OPENOCD/scripts/interface/cmsis-dap.cfg -f scripts/target/nrf51.cfg
    ```
* start the debugger: 
    ```
    cgdb -d arm-none-eabi-gdb -x gdbinit build/bbc-microbit-classic-gcc/source/calliope-playground
    ```

> Helpful ebugger commands are `break main`, `c` for continue. If you recompile, there
> is no need to restart all the above, just to `lo` (reloads code), `r` (restart). If the 
> debugger behaves strange, try `mon reset` (resets chip).

Happy debugging.
