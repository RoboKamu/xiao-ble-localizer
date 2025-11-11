In order for this library to be included with

    #include "heartbeat.h"

in your zephyr src/main.c file two things have to be true:

1. CMake for build inclusion
You have the CMakeLists.txt file for both this library and in application folder (or some variant of the CMake to build for your specifik project structure)

2. Kconfig for enabling the library 
Kconfig is meant as a tool for configuring the kernel and subsystem for specific applications at build time without having to change source code. 

In this case, without a Kconfig you would get some error stating that something like: undefined reference to `z_timer...` even though the header file included. 
That is because the library is not enabled, meaning it is not actually linked and is excluded from the final build. 

To start Kconfig: 

> [insrt you build as usual here; west build ...] -t menuconfig

This starts menuconfig where you can configure the build for your board.

This is only if you want to use you on kconfig, but the proj.conf already 
includes config for the GPIO and BT

**Extra Feature** 

I could not be able to make the heartbeat files work without the main.c
calling init funtion directly, via k_timer_init or the macro like now. 

Prefferably, the only function main.c should "see" is the heartbeat_init()
