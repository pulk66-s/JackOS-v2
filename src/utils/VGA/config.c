#include "VGA/config.h"

uint16_t *get_vga_ptr() {
    return ((uint16_t *)0xB8000);
}