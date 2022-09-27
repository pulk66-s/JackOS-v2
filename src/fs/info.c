#include "fs/info.h"

char *fs_get_current_path(void)
{
    return (_fs.current->abs_path);
}

const file_t **fs_get_curr_children(void)
{
    return ((const file_t **)_fs.current->children);
}

int fs_is_file(const file_t *file)
{
    return ((file->flags & FS_FLAG_FILE) == 0);
}

int fs_is_folder(const file_t *file)
{
    return ((file->flags & FS_FLAG_DIRECTORY) != 0);
}

int fs_is(const file_t *file, uint8_t flags)
{
    return ((file->flags & flags) != 0);
}
