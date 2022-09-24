#ifndef __JOS_KERNEL_H__
    #define __JOS_KERNEL_H__

    #include <stddef.h>
    #include <stdint.h>
    #include "string.h"

    #define VGA_WIDTH 80
    #define VGA_HEIGHT 25

/**
 * @brief VGA Memory buffer (OxB8000)
 */
uint16_t *video_mem = (uint16_t*)(0xB8000);

/**
 * @brief Entry point of the kernel,
 * must be called by the kernel asm loader.
 */
void kernel_main();

#endif