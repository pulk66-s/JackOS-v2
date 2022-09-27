#include "string/split.h"

static int is_delim(char c, const char *delim)
{
    for (int i = 0; delim[i]; i++) {
        if (c == delim[i])
            return (1);
    }
    return (0);
}

static size_t count_delim(const char *str, const char *delim)
{
    size_t count = 0;

    for (size_t i = 0; str[i]; i++) {
        if (is_delim(str[i], delim)) {
            count++;
            for (; is_delim(str[i], delim); i++);
        }
    }
    return (count);
}

char **str_split(const char *str, const char *delim)
{
    size_t delim_c = count_delim(str, delim);
    size_t max_len = strlen(str);
    char **result = malloc(sizeof(char *) * (delim_c + 1));
    char buff[max_len];
    size_t buff_i = 0;
    size_t result_i = 0;
    size_t str_i = 0;

    memset(buff, 0, max_len);
    memset(result, 0, sizeof(char *) * (delim_c + 1));
    for (; is_delim(str[str_i], delim); str_i++);
    for (; str[str_i]; str_i++) {
        if (is_delim(str[str_i], delim)) {
            result[result_i++] = strdup(buff);
            memset(buff, 0, max_len);
            buff_i = 0;
            for (; is_delim(str[str_i], delim); str_i++);
            str_i--;
        } else {
            buff[buff_i++] = str[str_i];
        }
    }
    if (buff[0])
        result[result_i] = strdup(buff);
    return (result);
}