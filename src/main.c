#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


#include "life.h"


union Color {
    uint32_t value;
    struct {
        uint8_t r, g, b, a;
    };
};
#define COLOR(val) (union Color){.value = val}
#define DECOLOR(color) color.r, color.g, color.b, color.a


/* Generate SDL_Rect's to fill a region
 * Do up to integer precision, meaning 0.5 arect will be ignored */
void CreateRectangles(SDL_Rect *rects, uint32_t width, uint32_t height,
                       uint32_t from_x, uint32_t to_x,
                       uint32_t from_y, uint32_t to_y);
void RenderGameOfLife(SDL_Renderer *rend, struct LIFE golife, SDL_Rect *rects,
                      uint32_t nrects_x, uint32_t nrects_y,
                      union Color alive_color, union Color dead_color);


int main(int argc, const char *argv[]) {

    /* CHANGE THOSE VALUES */
    const uint32_t width = 800, height = 600;
    const uint32_t cell_width = 5;
    
    srand(time(NULL));

    SDL_InitSubSystem(SDL_INIT_VIDEO);
    SDL_Window *win;
    SDL_Renderer *rend;
    win = SDL_CreateWindow("Game Of Life", SDL_WINDOWPOS_UNDEFINED_MASK,
            SDL_WINDOWPOS_UNDEFINED_MASK, width, height, SDL_WINDOW_SHOWN);
    rend = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);

    /* Pre-rendering */
    const uint32_t cells_x = width/cell_width;
    const uint32_t cells_y = height/cell_width;
    SDL_Rect cells[cells_x * cells_y]; // 1D array for simplicity
    CreateRectangles(cells, cell_width, cell_width, 0, width, 0, height);

    struct LIFE golife;
    life_generate(&golife, cells_x, cells_y);

    /* Start */
    SDL_Event event;
    bool run = true;
    uint32_t generation = 0;
    while (run) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                run = false;
                break;
            }
        }
        SDL_Log("Generation %d", generation++);
        RenderGameOfLife(rend, golife, cells, cells_x, cells_y, COLOR(0xffffffff), COLOR(0x0));
        SDL_RenderPresent(rend);
        life_next(golife);
    }
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}


void CreateRectangles(SDL_Rect *rects, uint32_t width, uint32_t height,
                       uint32_t from_x, uint32_t to_x,
                       uint32_t from_y, uint32_t to_y) {
    uint32_t nrects_x = (to_x - from_x)/width;
    uint32_t nrects_y = (to_y - from_y)/height;

    uint32_t x, y;
    uint32_t i;
    for (i = 0; i < nrects_x * nrects_y; i++) {
        x = from_x + (width * (i % nrects_x));
        y = from_y + height * (i - (i % nrects_x))/nrects_x;
        // Since index = row * ncols + col
        // We get (index - col)/ncols = row
        rects[i].x = x;
        rects[i].y = y;
        rects[i].w = width;
        rects[i].h = height;
    }
}

void RenderGameOfLife(SDL_Renderer *rend, struct LIFE golife, SDL_Rect *rects,
                      uint32_t nrects_x, uint32_t nrects_y,
                      union Color alive_color, union Color dead_color) {
    uint32_t len = nrects_x * nrects_y;
    bool *frame = golife.frame;
    for (uint32_t i = 0; i < len; i++) {
        if (frame[i]) {
            SDL_SetRenderDrawColor(rend, DECOLOR(alive_color));
        } else {
            SDL_SetRenderDrawColor(rend, DECOLOR(dead_color));
        }
        SDL_RenderFillRect(rend, &(rects[i]));
    }
}
