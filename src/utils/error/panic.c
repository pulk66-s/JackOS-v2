#include "error/panic.h"

void panic(const char *msg) {
    printf("PANIC: %s", VGA_COLOR_RED, 0, 0, msg);
    for (;;);
}