#ifndef __JOS_HEAP_HEAP_H__
    #define __JOS_HEAP_HEAP_H__

    #include "memory.h"
    #include "error.h"

    #include "heap/alloc.h"
    #include "heap/free.h"
    #include "heap/config.h"

/**
 * @brief Initialize the heap
 */
void heap_init();

#endif