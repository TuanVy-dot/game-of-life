#include "life.h"
#include <stdlib.h>
#include <stdbool.h>


/* Take a life struct and generate a random life map 
 * Return 1 for failure */
int32_t life_generate(struct LIFE *life, uint32_t width, uint32_t height) {
    bool *frame = malloc(width * height);
    if (!frame) {
        return 1;
    }
    bool *prev = malloc(width * height);
    if (!prev) {
        return 1;
    }
    life -> frame = frame;
    life -> prev = prev;
    randbit_array(frame, width * height);
    life -> width = width;
    life -> height = height;
    return 0;
}
