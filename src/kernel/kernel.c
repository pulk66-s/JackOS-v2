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

void kernel_main() {
    terminal_initialize();
    load_gdt();
    heap_init();
    char *str = malloc(4100);
    free(str);
    printf("Hello, world! %d, je suis un grand fan de %s Halliday et son single %c.", 0x0F, 0, 0, 321, "Johny", 'C');
    while(1) {}
}
