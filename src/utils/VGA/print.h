#ifndef __JOS_UTILS_VIDEO_MEMORY_PRITNT_H__
    #define __JOS_UTILS_VIDEO_MEMORY_PRITNT_H__

    #include <stdint.h>
    #include <stdarg.h>
    #include "VGA/config.h"
    #include "string.h"

/**
 * @brief Prints a string to the screen with format.
 * @param format The format of the string.
 * @param x The x position of the string.
 * @param y The y position of the string.
 * @param color The color of the string.
 * @param ... The arguments to the format.
 */
size_t printf(const char *format, uint8_t color, uint8_t x, uint8_t y, ...);

/**
 * @brief Prints a string to the screen.
 * @param str The string to print.
 * @param color The color of the string.
 * @param x The x position of the string.
 * @param y The y position of the string.
 */
size_t print(const char *str, uint8_t color, uint8_t x, uint8_t y);

#endif