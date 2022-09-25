#include "memory/free.h"

void free(void *ptr)
{
    heap_free(ptr);
}