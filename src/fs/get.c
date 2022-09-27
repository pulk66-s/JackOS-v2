#include "fs/get.h"

file_t *fs_get_child(const file_t *curr, const char *file)
{
    for (size_t i = 0; curr->children[i]; i++) {
        if (strcmp(curr->children[i]->name, file))
            return (curr->children[i]);
    }
    return (NULL);
}
