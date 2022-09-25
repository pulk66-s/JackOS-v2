#ifndef __JOS_UTILS_MEMORY_FREE_H__
    #define __JOS_UTILS_MEMORY_FREE_H__

    #include "heap/heap.h"

/**
 * @brief JOS free memory function, it's free a pointer that's been allocated
 * in heap
 * @param ptr: the pointer to free in heap
 */
void free(void *ptr);

#endif