#ifndef __JOS_KERNEL_H__
    #define __JOS_KERNEL_H__

    #include "VGA.h"
    #include "gdt/gdt.h"
    #include "heap/heap.h"
    #include "memory.h"
    #include "fs/fs.h"

/**
 * @brief Entry point of the kernel,
 * must be called by the kernel asm loader.
 */
void kernel_main();

#endif