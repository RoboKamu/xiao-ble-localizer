# create target
add_library(heartbeat STATIC src/heartbeat.c)

# add include directories for compilation
target_include_directories(
    heartbeat
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set compile option
# link with Zephyr core interface for usage with eg. zephyr/kernal.h and the like
target_link_libraries(heartbeat PRIVATE zephyr_interface)
