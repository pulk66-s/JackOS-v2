#ifndef __JOS_FS_INFO_H__
    #define __JOS_FS_INFO_H__

    #include "fs/config.h"
    #include "stddef.h"

/**
 * @brief get the current working directory
 */
char *fs_get_current_path();

/**
 * @brief get the curr children of the current working directory
 * @return: the children of the current working directory
 */
const file_t **fs_get_curr_children();

/**
 * @brief check if the file is a directory
 * @param file: the file to check
 * @return: 1 if the file is a directory, 0 if not
 */
int fs_is_file(const file_t *file);

/**
 * @brief check if the file is a directory
 * @param file: the file to check
 * @return: 1 if the file is a directory, 0 if not
 */
int fs_is_folder(const file_t *file);

/**
 * @brief check if the file have the given flags
 * @param file: the file to check
 * @param flags: the flags to check
 * @return: 1 if the file have the given flags, 0 if not
 */
int fs_is(const file_t *file, uint8_t flags);

#endif