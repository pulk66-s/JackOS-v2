#include "gdt/init.h"

void load_gdt(void) {
    gdt_entry_t gdt_real[JACKOS_GDT_TOTAL_ENTRIES];
    gdt_t gdt_structured[JACKOS_GDT_TOTAL_ENTRIES] = {
        {.base = 0x00, .limit = 0x00, .type = 0x00},                    // NULL Segment
        {.base = 0x00, .limit = 0xffffffff, .type = 0x9a},              // Kernel code segment
        {.base = 0x00, .limit = 0xffffffff, .type = 0x92},              // Kernel data segment
        {.base = 0x00, .limit = 0xffffffff, .type = 0xf8},              // User code segment
        {.base = 0x00, .limit = 0xffffffff, .type = 0xf2},              // User data segment
    };

    memset(gdt_real, 0x00, sizeof(gdt_real));
    gdt_structured_to_gdt(gdt_real, gdt_structured, JACKOS_GDT_TOTAL_ENTRIES);
    gdt_load(gdt_real, sizeof(gdt_real));
}