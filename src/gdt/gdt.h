#ifndef __JOS_GDT_GDT_H__
    #define __JOS_GDT_GDT_H__

    #include <stdint.h>
    #include "error.h"
    #include "config.h"
    #include "init.h"
    #include "memory.h"

/**
 * @brief GDT entry structure
 */
typedef struct gdt_entry_s {
    uint16_t segment;
    uint16_t base_first;
    uint8_t base;
    uint8_t access;
    uint8_t high_flags;
    uint8_t base_24_31_bits;
} __attribute__((packed)) gdt_entry_t;

/**
 * @brief GDT pointer structure
 */
typedef struct gdt_s {
    uint32_t base;
    uint32_t limit;
    uint8_t type;
} gdt_t;

/**
 */
void gdt_load(gdt_entry_t *gdt, int size);
void gdt_structured_to_gdt(gdt_entry_t *gdt, gdt_t *ctured_gdt, int total_entires);

#endif