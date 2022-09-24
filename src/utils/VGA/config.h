#ifndef __JOS_UTILS_VIDEO_MEMORY_CONFIG_H__
    #define __JOS_UTILS_VIDEO_MEMORY_CONFIG_H__

    #include <stdint.h>

    #define VGA_ADDRESS 0xB8000
    #define VGA_WIDTH 80
    #define VGA_HEIGHT 25

    #define VGA_COLOR_BLACK 0
    #define VGA_COLOR_BLUE 1
    #define VGA_COLOR_GREEN 2
    #define VGA_COLOR_CYAN 3
    #define VGA_COLOR_RED 4
    #define VGA_COLOR_MAGENTA 5
    #define VGA_COLOR_BROWN 6
    #define VGA_COLOR_LIGHT_GREY 7
    #define VGA_COLOR_DARK_GREY 8
    #define VGA_COLOR_LIGHT_BLUE 9
    #define VGA_COLOR_LIGHT_GREEN 10
    #define VGA_COLOR_LIGHT_CYAN 11
    #define VGA_COLOR_LIGHT_RED 12
    #define VGA_COLOR_LIGHT_MAGENTA 13
    #define VGA_COLOR_LIGHT_BROWN 14
    #define VGA_COLOR_WHITE 15

/**
 * @brief get the pointer adress of the VGA memory. The VGA address is define with the macro VGA_ADDRESS.
 * @return The adress of the VGA memory.
 */
uint16_t *get_vga_ptr();

#endif