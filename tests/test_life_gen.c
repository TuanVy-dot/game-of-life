#include "life.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[]) {
    srand(time(NULL));
    struct LIFE life;
    life_generate(&life, 25, 25);
    print_life(life);
    return 0;
}
