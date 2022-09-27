#include "fs/create.h"

static int create_abs_path(const file_t *parent, file_t *curr, const char *file)
{
    if (!parent || !curr || !file)
        return (0);
    strcat(curr->abs_path, parent->abs_path);
    strcat(curr->abs_path, file);
    strcat(curr->abs_path, "/");
    return (1);
}

static file_t *create_default_file(const file_t *curr, const char *file, uint8_t flags)
{
    file_t *new_file = malloc(sizeof(file_t));

    memset(new_file, 0, sizeof(file_t));
    memset(new_file->children, 0, sizeof(new_file->children));
    strcat(new_file->name, file);
    new_file->flags = flags;
    new_file->size = 0;
    new_file->parent = (file_t *)curr;
    if (!create_abs_path(curr, new_file, file))
        return (NULL);
    return (new_file);
}

static int add_children(file_t *curr, const char *file, uint8_t flags)
{
    size_t child_index = 0;
    file_t *new_file = NULL;

    for (; curr->children[child_index]; child_index++);
    if (child_index >= FS_MAX_CHILDREN)
        return (0);
    new_file = create_default_file(curr, file, flags);
    printf("                                ", 0x0f, 0, 10);
    printf("Adding %s", 0x0f, 0, 10);
    if (!new_file)
        return (0);
    curr->children[child_index] = new_file;
    return (1);
}

static int browse_files(file_t *curr, const char **files, uint8_t flags)
{
    file_t *child = NULL;

    for (size_t i = 0; files[i]; i++) {
        if (files[i + 1] == 0) {
            return (add_children(curr, files[i], flags));
        } else {
            child = fs_get_child(curr, files[i]);
            if (!child || !fs_is_folder(child))
                return (0);
            curr = child;
        }
    }
    return (1);
}

int fcreate(const char *path, uint8_t flags)
{
    int root_start = path[0] == '/';
    const char **files = (const char **)str_split(path, "/");
    file_t *curr = NULL;

    if (files == NULL || files[0] == NULL)
        return (0);
    curr = root_start ? &_fs.root : _fs.current;
    if (!curr)
        return (0);
    return (browse_files(curr, files, flags));
}