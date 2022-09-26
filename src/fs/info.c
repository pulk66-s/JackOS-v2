#include "fs/info.h"

char *fs_get_current_path(void)
{
    return (_fs.current->abs_path);
}