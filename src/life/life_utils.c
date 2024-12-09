#include "life.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


/* GENERATE BIT VALUES BUT STORE IN BYTES */


/* Slightly faster printf if there are no format
 * Actually not really faster much, but why not? 
 * I love saving 0.0000001 ms */
void print(const char *s) {
    while (*s) {
        putchar(*s++);
    }
}


bool randbit(void) {
    return rand() & 1;
}


/* Set an array to a stream of bytes with random bit values (0/1) */
void randbit_array(bool *array, uint32_t length) {
    while (length--) {
        *array = randbit();
        array++;
    }
}


/* Print a flat byte array as 2D array
 * This was because for simplicity,
 * I don't want the array to be *[]
 * It is not pretty */
void print_2d_bit_array(bool *array, uint32_t width, uint32_t height) {
    print("[\n");
    for (uint32_t i = 0; i < height; i++) {
        print("    [");
        for (uint32_t j = 0; j < width; j++) {
            printf("%u", array[i * width + j]);
            if (j < width - 1) {
                print(", ");
            }
        }
        putchar(']'); // I think putchar would be faster than print 2 bytes str
        if (i < height - 1) {
            putchar(',');
        }
        putchar('\n');
    }
    print("]\n");
}


void print_life(struct LIFE life) {
    printf("Width: %u | Height: %u\nFrame: ", life.width, life.height);
    print_2d_bit_array(life.frame, life.width, life.height);
}


uint32_t count_adj(bool *frame, uint32_t width, uint32_t height,
                   uint32_t row, uint32_t col) {
    // The set of all directions
    static int32_t direction[][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
    uint32_t count = 0;
    
    int32_t mx, my;
    for (uint32_t i = 0; i < sizeof(direction)/sizeof(direction[0]); i++) {
        my = direction[i][0];
        mx = direction[i][1];
        if (NOTINRANGE(col + mx, 0, width) || NOTINRANGE(row + my, 0, height)) {
            continue;
        }
        count += frame[(row + my) * width + (col + mx)];
    }
    return count;
}
