#ifndef __JOS_FS_GET_H__
    #define __JOS_FS_GET_H__

    #include "fs/config.h"
    #include "string.h"

/**
 * @brief Get the file or directory at the given path
 * @param curr: The current directory
 * @param file: The path to the file or directory
 * 
 */
file_t *fs_get_child(const file_t *curr, const char *file);

/**
 * @brief get the file or directory at the given path
 * @param path: the path to the file or directory
 * @return the file or directory
 */
file_t *fget(const char *path);

#endif