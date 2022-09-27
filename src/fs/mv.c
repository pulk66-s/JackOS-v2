#include "fs/mv.h"

int fs_cd(const char *path)
{
    char **files = str_split(path, "/");
    file_t *child = NULL;
    file_t *curr = _fs.current;

    if (files == NULL)
        return (0);
    for (size_t i = 0; files[i]; i++) {
        child = fs_get_child(curr, files[i]);
        if (!child)
            return (0);
        if (files[i + 1] && !fs_is_folder(child))
            return (0);
        curr = child;
    }
    _fs.current = curr;
    return (1);
}