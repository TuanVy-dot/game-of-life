#include "life.h"
#include <stdint.h>
#include <time.h> 
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

int main(int argc, const char *argv[]) {
    srand(time(NULL));
    bool bit_array[HEIGHT][WIDTH];
    randbit_array((bool *)bit_array, HEIGHT * WIDTH);
    print_2d_bit_array((bool *)bit_array, WIDTH, HEIGHT);
    return 0;
}
