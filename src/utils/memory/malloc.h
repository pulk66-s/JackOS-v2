#ifndef __JOS_UTILS_MEMORY_MALLOC_H__
    #define __JOS_UTILS_MEMORY_MALLOC_H__

    #include "heap/heap.h"
    #include "stddef.h"

/**
 * @brief Allocates a block of memory in the heap
 * the return block size is always a multiple of HEAP_BLOCK_SIZE
 * @param size The size of the block to allocate
 * @return A pointer to the allocated block
 */
void *malloc(size_t size);

#endif