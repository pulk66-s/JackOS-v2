#include "memory/memset.h"

void memset(void *ptr, char value, size_t size) {
    for (size_t i = 0; i < size; i++) {
        ((char *)ptr)[i] = value;
    }
}