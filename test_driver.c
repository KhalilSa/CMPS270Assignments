#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "main_functions.c"
#include "main_functions.h"

int main() {
    /*
        Testing msb(unsigned int bin) function
        partitions:
        a == 0,
        a > 0,
        a is a power of 2,
        a too large
    */
    assert(-1 == msb(0));
    assert(1 == msb(3));
    assert(6 == msb(64));
    assert(7 == msb(204));
    assert(lsb(2 * 2 * 2) == msb(2 * 2 * 2));

    /*
        Testing msb(unsigned int bin) function
        partitions:
        a == 0,
        a > 0,
        a is a power of 2,
        a too large
    */
    assert(-1 == lsb(0));
    assert(0 == lsb(3));
    assert(6 == lsb(64));
    assert(2 == lsb(204));

    /*
        Testing msb_lsb_diff(int msb, int lsb) function
        partitions:
        lsb < 0 or msb < 0,
        lsb > msb,
        lsb == msb,
        lsb < msb,
        msb or lsb too large
    */
    // covers lsb <  0 or msb < 0
    assert(msb_lsb_diff(3, -4) == -1);
    assert(msb_lsb_diff(-2, 1) == -1);
    assert(msb_lsb_diff(-1, -1) == -1);
    assert(msb_lsb_diff(INT_MAX, -34) == -1);
    assert(msb_lsb_diff(INT_MIN, 45) == -1);


    // covers lsb > msb
    assert(msb_lsb_diff(3, 4) < 0);
    // covers lsb == msb
    // covers num is a power of 2
    assert(msb_lsb_diff(12, 12) == 0);
    assert(msb_lsb_diff(lsb(1), msb(1)) == 0);
    assert(msb_lsb_diff(lsb(8), msb(8)) == 0);

    // cover lsb < msb
    assert(msb_lsb_diff(msb(9), lsb(9)) == 3);

    /*
        Testing binary(int num) function
        partitions:
        num < 0,
        num == 0,
        num > 0,
        num is a power of 2,
        num too large
        
    */
    // covers num < 0
    assert(binary(-34) != -1);
    // covers num == 0
    assert(binary(0) == 0);
    // cover num > 0
    assert(binary(6) == 110);
    // covers num is a power of 2
    assert(binary(32) == 100000);
    // cover num is too large, there will be an overflow
    assert(binary(UINT_MAX + 1) != -1 );

    
    printf("All tests passed!!\n");
    return 0;
}
