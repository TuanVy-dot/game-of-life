#include "life.h"
#include <assert.h>
#include <stdint.h>

uint32_t count_adj(bool *frame, uint32_t width, uint32_t height,
                   uint32_t row, uint32_t col);

int main() {
    bool frame1[] = {
        1, 0, 0, 1, 0,
        1, 1, 0, 0, 1,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 1
    };
    assert(count_adj(frame1, 5, 4, 1, 1) == 4);
    assert(count_adj(frame1, 5, 4, 0, 0) == 2);
    assert(count_adj(frame1, 5, 4, 3, 4) == 2);
    assert(count_adj(frame1, 5, 4, 2, 2) == 4);
    assert(count_adj(frame1, 5, 4, 0, 4) == 2);
    
    bool frame2[] = {
        0, 0, 0, 0,
        0, 0, 0, 0
    };
    assert(count_adj(frame2, 4, 2, 0, 0) == 0);
    
    bool frame3[] = {
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1
    };
    assert(count_adj(frame3, 5, 2, 0, 0) == 3);
    assert(count_adj(frame3, 5, 2, 1, 4) == 3);
    
    bool frame4[] = {
        0, 0, 0,
        0, 0, 0,
        0, 0, 0
    };
    assert(count_adj(frame4, 3, 3, 1, 1) == 0);
    
    bool frame5[] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };
    assert(count_adj(frame5, 3, 3, 0, 0) == 1);
    assert(count_adj(frame5, 3, 3, 2, 2) == 1);
    
    bool frame6[] = {
        1
    };
    assert(count_adj(frame6, 1, 1, 0, 0) == 0);

    return 0;
}
