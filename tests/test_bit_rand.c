#include "life.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
    srand(time(NULL));
    printf("A random bit: %u \n", randbit());
    printf("A random bit: %u \n", randbit());
    printf("A random bit: %u \n", randbit());
    return 0;
}
