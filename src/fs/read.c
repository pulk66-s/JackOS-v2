#include "fs/read.h"

uint8_t *fread(const char *path, size_t *size)
{
    file_t *file = fget(path);
    size_t buff_read = 0;
    uint8_t *buff = NULL;

    if (!file)
        return (NULL);
    *size = file->size;
    buff = malloc(file->size);
    if (!buff)
        return (NULL);
    memset(buff, 0, file->size);
    for (size_t i = 0; i < file->size; i++) {
        buff[buff_read++] = file->data[i];
    }
    return (buff);
}