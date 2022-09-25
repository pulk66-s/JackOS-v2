#include "memory/malloc.h"

void *malloc(size_t size) {
    return (heap_alloc(size));
}