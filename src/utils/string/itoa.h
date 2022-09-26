#ifndef __JOS_UTILS_STRING_ITOA_H__
    #define __JOS_UTILS_STRING_ITOA_H__

    #include "stddef.h"

    #include "string/revstr.h"

/**
 * @brief Converts an integer to a string.
 * @param value The integer to convert.
 * @param str The string to store the result.
 * @param base The base of the integer.
 */
void itoa(int value, char *str, uint8_t base);

#endif