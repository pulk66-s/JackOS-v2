#ifndef __JOS_FS_CREATE_H__
    #define __JOS_FS_CREATE_H__

    #include "fs/config.h"
    #include "fs/get.h"
    #include "fs/info.h"
    #include "stddef.h"
    #include "string.h"

/**
 * @brief create a file in the file system
 * @param path: the path of the file
 * @param flags: the flags of the file
 * @return 1 if success, 0 if failed
 */
int fcreate(const char *path, uint8_t flags);

#endif