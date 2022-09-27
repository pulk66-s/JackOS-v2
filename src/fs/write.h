#ifndef __JOS_FS_WRITE_H__
    #define __JOS_FS_WRITE_H__

    #include "fs/config.h"
    #include "fs/get.h"
    #include "stddef.h"

/**
 * @brief write data to a file in bytes
 * @param path: the path of the file
 * @param data: the data to write
 * @param size: the size of the data
 * @return 1 if success, 0 if failed
 */
int fwrite_b(const char *path, const uint8_t *data, size_t size);

#endif