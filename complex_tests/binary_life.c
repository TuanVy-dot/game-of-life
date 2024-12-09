#include "life.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler() {
    printf("\033[?1049l");
    exit(0);
}

int main(int argc, const char **argv) {
    signal(SIGINT, sigint_handler);
    srand(time(NULL));
    struct LIFE life;
    life_generate(&life, 25, 25);
    printf("\033[?1049h");
    for (int i = 0; i < 100; i++) {
        printf("\033[H\033[2J");
        printf("Frame %d\n", i);
        print_life(life);
        fflush(stdin);
        sleep(1);
        life_next(life);
    }
    printf("\033[?1049l");
    return 0;
}
