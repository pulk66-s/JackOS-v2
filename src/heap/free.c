#include "heap/free.h"

void heap_free(void *ptr)
{
    uint8_t *base_ptr = ptr - 1;

    *base_ptr = HEAP_FREE_FLAG;
}