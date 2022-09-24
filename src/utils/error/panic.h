#ifndef __JOS_UTILS_ERROR_PANIC_H__
    #define __JOS_UTILS_ERROR_PANIC_H__

    #include "VGA.h"

/**
 * @brief Panic function, called when a fatal error occurs.
 */
void panic(const char *message);

#endif