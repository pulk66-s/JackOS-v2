#ifndef __JOS_HEAP_FREE_H__
    #define __JOS_HEAP_FREE_H__

    #include "heap/config.h"
    #include "VGA.h"
    #include "stddef.h"

/**
 * @brief heap pointer free, it's used to free the space when not used anymore
 * @param ptr: the pointer you want to free
 */
void heap_free(void *ptr);

#endif