#ifndef __JOS_FS_READ_H__
    #define __JOS_FS_READ_H__

    #include "fs/config.h"
    #include "fs/get.h"
    #include "stddef.h"

/**
 * @brief Read data from a file.
 * @param path Path to the file.
 * @param size Size of the buffer that was read. set to NULL if not needed
 * @return datas
 */
uint8_t *fread(const char *path, size_t *size);

#endif