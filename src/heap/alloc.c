#include "heap/alloc.h"

/**
 * @brief Alignment of the pointer to the next HEAP_BLOCK_SIZE
 * @param size the size to align
 * @return the aligned size
 */
static size_t align_size(size_t size)
{
    if (size % HEAP_BLOCK_SIZE == 0) {
        return (size);
    }
    return ((size - size % HEAP_BLOCK_SIZE) + HEAP_BLOCK_SIZE);
}

/**
 * @brief Get the index of block in the heap table that can fit the next block_count blocks
 * @param block_count the number of blocks to fit
 * @return the index of the block in the heap table
 */
static size_t get_block_free_index(heap_table_t *table, size_t block_count)
{
    size_t block_s = -1;
    size_t block_c = 0;

    for (int i = 0; i < table->total_block_size; i++) {
        if (table->entries[i] == HEAP_FREE_FLAG) {
            if (block_c == 0) {
                block_c = 1;
                block_s = i;
            } else {
                block_c++;
            }
            if (block_c == block_count) {
                break;
            }
        } else {
            block_c = 0;
            block_s = -1;
        }
    }
    if (block_s < 0 || block_c < block_count) {
        panic("No more space in the heap");
    }
    return (block_s);
}

/**
 * fill the table entry index with the flag given
 * @param table the heap table
 * @param index the index of the entry to fill
 * @param flag the flag to fill the entry with
 */
static void fill_blocks(heap_table_t *table, size_t index, uint8_t flag)
{
    table->entries[index] = flag;
}

void *heap_alloc(size_t size)
{
    size_t aligned_size = align_size(size);
    size_t block_count = aligned_size / HEAP_BLOCK_SIZE;
    heap_table_t *table = _heap.table;
    size_t block_free_index = get_block_free_index(table, block_count);

    for (size_t i = 0; i < block_count; i++) {
        uint8_t flag = HEAP_USED_FLAG;
        if (i < block_count - 1) {
            flag |= HEAP_HAS_NEXT_FLAG;
        }
        fill_blocks(table, block_free_index + i, flag);
    }
    return (table->entries + (block_free_index * HEAP_BLOCK_SIZE) + 1);
}