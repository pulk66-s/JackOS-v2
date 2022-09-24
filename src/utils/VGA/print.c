#include "VGA/print.h"

static size_t print_char(char c, uint8_t color, uint8_t x, uint8_t y) {
    uint16_t *video_mem = get_vga_ptr();
    video_mem[(y * VGA_WIDTH) + x] = c | (color << 8);
    return (1);
}

static size_t print_string(char *str, uint8_t color, uint8_t x, uint8_t y) {
    return (print(str, color, x, y));
}

static size_t print_int(int num, uint8_t color, uint8_t x, uint8_t y) {
    char str[16];

    itoa(num, str, 10);
    return (print_string(str, color, x, y));
}

static size_t parse_instruction(const char *str, va_list *args, uint8_t color, uint8_t x, uint8_t y) {
    switch (*str) {
        case 'd':
            return (print_int(va_arg(*args, int), color, x, y));
        case 's':
            return (print_string(va_arg(*args, char *), color, x, y));
        case 'c':
            return (print_char(va_arg(*args, int), color, x, y));
        default:
            return (0);
    }
    return (0);
}

size_t printf(const char *str, uint8_t color, uint8_t x, uint8_t y, ...) {
    size_t printed_len = 0;
    size_t printed_instruction_len = 0;

    va_list args;
    va_start(args, y);
    for (; *str != '\0'; str++) {
        if (*str == '%') {
            printed_instruction_len = parse_instruction(++str, &args, color, x, y);
            printed_len += printed_instruction_len;
            x += printed_instruction_len;
        } else {
            printed_len += print_char(*str, color, x++, y);
        }
        if (x >= VGA_WIDTH) {
            x = 0;
            y++;
        }
    }
    va_end(args);
    return (printed_len);
}

size_t print(const char *str, uint8_t color, uint8_t x, uint8_t y) {
    uint16_t *vga_ptr = get_vga_ptr();
    uint16_t *vga_ptr_offset = vga_ptr + (y * VGA_WIDTH + x);
    size_t len = 0;

    while (*str) {
        len++;
        *vga_ptr_offset++ = *str++ | (color << 8);
    }
    return (len);
}