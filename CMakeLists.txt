# Simple CMake that builds with a custom lib folder 

# Minimum CMake version 
cmake_minimum_required(VERSION 3.20.0)

# Locate Zephyr RTOS source dir 
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# Name the project 
project(xiao_ble_localizer LANGUAGES C)

# include libraries
add_subdirectory(lib/heartbeat)

# Specify source for building target and its dependencies  
target_sources(app PRIVATE 
    src/main.c
    src/observer.c
)

# Specify libraries/flags for the linking process
target_link_libraries(app PRIVATE heartbeat)
