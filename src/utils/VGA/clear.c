#include "VGA/clear.h"

void clear_terminal()
{
    uint16_t *video_memory = get_vga_ptr();

    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        video_memory[i] = ' ' | (VGA_COLOR_BLACK << 8);
    }
}