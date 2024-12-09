#include "life.h"
#include <stdlib.h>


/* Update life to the next frame 
 * Prev is the previous state */
int32_t arrlife_next(bool *frame, bool *prev, uint32_t width, uint32_t height) {
    memcpy(prev, frame, width * height);

    uint32_t count;
    uint32_t flat_index;
    for (uint32_t row = 0; row < height; row++) {
        for (uint32_t col = 0; col < width; col++) {
            count = count_adj(prev, width, height,
                              row, col);
            flat_index = row * width + col;
            if (prev[flat_index]) {
                // isliving
                if (count < 2 || count > 3) {
                    frame[flat_index] = false; // dead
                }
            } else if (count == 3) {
                frame[flat_index] = true;
            }
        }
    }
    return 0;
}

int32_t life_next(struct LIFE life) {
    return arrlife_next(life.frame, life.prev, life.width, life.height);
}
