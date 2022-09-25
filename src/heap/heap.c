#include "heap.h"

static heap_t heap;
static heap_table_t heap_table;

static void init_heap_struct()
{
    memset(&heap, 0, sizeof(heap_t));
    heap.saddr = (void *)HEAP_ADDR;
}

/**
 * @brief Initialize the heap table, by memseting it to 0
 * and fill datas with start adress of the heap and the total size
 */
static void init_heap_table()
{
    memset(&heap_table, 0, sizeof(heap_table_t));
    heap_table.entries = (void *)HEAP_ADDR;
    heap_table.total_block_size = HEAP_BLOCK_COUNT;
    heap.table = &heap_table;
    memset(heap.table->entries, HEAP_EMPTY_FLAG, HEAP_SIZE);
}

/**
 * @brief Checking the aligment of the pointer in the heap
 * Checking if the pointer is aligned to HEAP_BLOCK_SIZE by checking the modulo
 * value
 * @return 1 if the pointer is aligned, 0 otherwise
 */
static int check_align_size(void *ptr)
{
    return ((size_t)ptr % HEAP_BLOCK_SIZE == 0);
}

/**
 * @brief Verify the alignmnent of the heap,
 * The heap must be aligned to HEAP_BLOCK_SIZE,
 * it's checking the starting address, the size and the end address
 */
static void checking_alignment()
{
    void *saddr = heap.saddr;
    void *eaddr = (void *)((uint32_t)saddr + HEAP_SIZE);

    if (!check_align_size(saddr) || !check_align_size(eaddr)) {
        panic("Heap starting address is not aligned to HEAP_BLOCK_SIZE");
    }
}

void heap_init()
{
    init_heap_struct();
    init_heap_table();
    checking_alignment();
}

