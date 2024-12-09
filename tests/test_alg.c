#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "life.h"

int compare_frames(bool *frame1, bool *frame2, uint32_t size) {
    for (uint32_t i = 0; i < size; ++i) {
        if (frame1[i] != frame2[i]) {
            return 0;  // Frames do not match
        }
    }
    return 1;  // Frames match
}

void test_life_next() {
    bool frame1[] = {
        0, 1, 0,
        1, 1, 1,
        0, 1, 0
    };
    bool expected1[] = {
        1, 1, 1,
        1, 0, 1,
        1, 1, 1
    };
    printf("Test 1:\n");
    print_2d_bit_array(frame1, 3, 3);
    print_2d_bit_array(expected1, 3, 3);
    arrlife_next(frame1, 3, 3);
    printf("After:\n");
    print_2d_bit_array(frame1, 3, 3);
    assert(compare_frames(frame1, expected1, 9));

    bool frame2[] = {
        0, 0, 0,
        0, 1, 0,
        0, 0, 0
    };
    bool expected2[] = {
        0, 0, 0,
        0, 0, 0,
        0, 0, 0
    };
    printf("Test 2:\n");
    print_2d_bit_array(frame2, 3, 3);
    print_2d_bit_array(expected2, 3, 3);
    arrlife_next(frame2, 3, 3);
    printf("After:\n");
    print_2d_bit_array(frame2, 3, 3);
    assert(compare_frames(frame2, expected2, 9));

    bool frame3[] = {
        1, 1, 1,
        1, 1, 1,
        1, 1, 1
    };
    bool expected3[] = {
        1, 0, 1,
        0, 0, 0,
        1, 0, 1
    };
    printf("Test 3:\n");
    print_2d_bit_array(frame3, 3, 3);
    print_2d_bit_array(expected3, 3, 3);
    arrlife_next(frame3, 3, 3);
    printf("After:\n");
    print_2d_bit_array(frame3, 3, 3);
    assert(compare_frames(frame3, expected3, 9));

    bool frame4[] = {
        1, 0, 1,
        0, 1, 0,
        1, 0, 1
    };
    bool expected4[] = {
        0, 1, 0,
        1, 0, 1,
        0, 1, 0
    };
    printf("Test 4:\n");
    print_2d_bit_array(frame4, 3, 3);
    print_2d_bit_array(expected4, 3, 3);
    arrlife_next(frame4, 3, 3);
    printf("After:\n");
    print_2d_bit_array(frame4, 3, 3);
    assert(compare_frames(frame4, expected4, 9));
}

int main() {
    test_life_next();
    return 0;
}
