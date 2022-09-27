#include "fs/init.h"

file_system_t _fs;

static file_t init_root()
{
    file_t root = {0};

    strcat(root.name, "/");
    strcat(root.abs_path, "/");
    memset(root.children, 0, sizeof(root.children));
    root.flags = FS_FLAG_DIRECTORY;
    root.size = 0;
    return (root);
}

void fs_init(void)
{
    _fs.root = init_root();
    _fs.current = &_fs.root;
}