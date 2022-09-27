#include "fs/get.h"

file_t *fs_get_child(const file_t *curr, const char *file)
{
    for (size_t i = 0; curr->children[i]; i++) {
        if (strcmp(curr->children[i]->name, file))
            return (curr->children[i]);
    }
    return (NULL);
}

file_t *fget(const char *path)
{
    int is_root = path[0] == '/';
    file_t *curr = is_root ? &_fs.root : _fs.current;
    const char **files = (const char **)str_split(path, "/");
    file_t *child = NULL;

    if (!files)
        return (NULL);
    for (size_t i = 0; files[i]; i++) {
        child = fs_get_child(curr, files[i]);
        if (!child)
            return (NULL);
        curr = child;
    }
    return (curr);
}