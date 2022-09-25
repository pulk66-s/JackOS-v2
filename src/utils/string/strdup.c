#include "string/strdup.h"

char *strdup(const char *str)
{
    size_t size = strlen(str) + 1;
    char *res = malloc(sizeof(char) * size);

    memset(res, 0, size);
    strcat(res, str);
    return (res);
}