#ifndef __JOS_UTILS_STRING_SPLIT_H__
    #define __JOS_UTILS_STRING_SPLIT_H__

    #include "stddef.h"
    #include "memory.h"
    #include "string/strlen.h"

/**
 * @brief split a string into a string array
 * @param str: the string to be split
 * @param delim: the delimiters
 */
char **str_split(const char *str, const char *delim);

#endif