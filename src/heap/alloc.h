#ifndef __JOS_HEAP_ALLOC_H__
    #define __JOS_HEAP_ALLOC_H__

    #include "heap/config.h"
    #include "error.h"
    #include "VGA.h"

/**
 * @brief Allocates a block of memory in the heap
 * the return block size is always a multiple of HEAP_BLOCK_SIZE
 * @param size The size of the block to allocate
 * @return A pointer to the allocated block
 */
void *heap_alloc(size_t size);

#endif