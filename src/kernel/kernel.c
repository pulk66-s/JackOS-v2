#include "kernel.h"

/**
 * @brief all our systems must be initialized here
 */
static void kernel_init()
{
    clear_terminal();
    load_gdt();
    heap_init();
    fs_init();
}

void kernel_main()
{
    kernel_init();
    printf("Hello, world! %d, je suis un grand fan de %s Halliday et son single %c.", 0x0F, 0, 20, 321, "Johny", 'C');
    for (;;);
}
