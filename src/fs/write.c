#include "fs/write.h"

int fwrite_b(const char *path, const uint8_t *data, size_t size)
{
    file_t *file = fget(path);

    if (!file || !data)
        return (0);
    file->size = 0;
    for (size_t i = 0; i < size; i++) {
        if (file->size >= FS_MAX_DATA_SIZE) {
            return (0);
        }
        file->size++;
        file->data[i] = data[i];
    }
    return (1);
}