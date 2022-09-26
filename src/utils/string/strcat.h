#ifndef __JOS_UTILS_STRING_STRCAT_H__
    #define __JOS_UTILS_STRING_STRCAT_H__

    #include "stddef.h"

/**
 * @brief concat the string in src into dest string, the dest pointer must have
 * enough memory.
 * @param dest: the destination pointer
 * @param src: the string to copy
 */
void strcat(char *dest, const char *src);

#endif