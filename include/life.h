#ifndef LIFE

#include <stdint.h>
#include <stdbool.h>

/* Check for in bound of array
 * That's why max is exclude in INRANGE
 * And similarly min in NOTINRANGE */
#define INRANGE(x, min, max) (x >= min && x < max)
#define NOTINRANGE(x, min, max) (x < min || x >= max)


struct LIFE {
    bool *frame; // Work as 2D array but declared as 1D for simplicity
    bool *prev; // use as snapshot to save the original state 
                // while frame is getting modify
    uint32_t width, height;
};

int32_t life_generate(struct LIFE *life, uint32_t width, uint32_t height);

int32_t arrlife_next(bool *frame, bool *prev, uint32_t width, uint32_t height);
int32_t life_next(struct LIFE life);

/* LIFE UTILS */
void print(const char *s);
bool randbit(void);
void randbit_array(bool *array, uint32_t length);
void print_2d_bit_array(bool *array, uint32_t width, uint32_t height);
void print_life(struct LIFE life);
uint32_t count_adj(bool *frame, uint32_t width, uint32_t height,
                   uint32_t row, uint32_t col);

#endif
