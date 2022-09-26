#include "kernel.h"

uint16_t terminal_make_char(char c, char colour) {
    return (colour << 8) | c;
}

void terminal_putchar(int x, int y, char c, char colour) {
    video_mem[(y * VGA_WIDTH) + x] = terminal_make_char(c, colour);
}

void terminal_initialize() {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            terminal_putchar(x, y, ' ', 0);
        }
    }
}

/**
 * @brief all our systems must be initialized here
 */
static void kernel_init()
{
    terminal_initialize();
    load_gdt();
    heap_init();
    fs_init();
}

void kernel_main() {
    kernel_init();
    printf("Current path: %s", 0x0F, 0, 13, fs_get_current_path());
    printf("Hello, world! %d, je suis un grand fan de %s Halliday et son single %c.", 0x0F, 0, 0, 321, "Johny", 'C');
    for (;;);
}
