#ifndef __JOS_FS_CONFIG_H__
    #define __JOS_FS_CONFIG_H__

    #include "stddef.h"

    #define FS_MAX_FILE_NAME_LEN    256
    #define FS_MAX_PATH_LEN         2048
    #define FS_MAX_CHILDREN         256

// FS flags

    #define FS_FLAG_DIRECTORY   0b00000001
    #define FS_FLAG_FILE        0b00000000

/**
 * @brief file information structure
 */
typedef struct file_s {
    char name[FS_MAX_FILE_NAME_LEN];
    uint8_t flags;
    uint32_t size;
    char abs_path[FS_MAX_PATH_LEN];
    struct file_s *children[FS_MAX_CHILDREN];
    struct file_s *parent;
} file_t;

/**
 * @brief file system configuration, including all file system information
 */
typedef struct file_system_s {
    file_t root;
    file_t *current;
} file_system_t;

extern file_system_t _fs;

#endif