#ifndef __JOS_UTILS_STRING_STRDUP_H__
    #define __JOS_UTILS_STRING_STRDUP_H__

    #include "string/strlen.h"
    #include "string/strcat.h"
    #include "memory.h"

/**
 * @brief function that takes a string and allocates and copy the content into
 * the results.
 * @param str: the string to duplicates
 */
char *strdup(const char *str);

#endif