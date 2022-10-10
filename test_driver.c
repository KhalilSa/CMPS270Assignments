#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "main_functions.c"
#include "main_functions.h"

int main() {
    /*
        Testing hamming_distance(int a, int b) function
        partitions:
        a == 0 && b == 0, 
        a == b,
        a >= 0 && b >= 0,
        a < 0 || b < 0,
        a or b too large
    */
    // covers a == 0 && b ==0
    assert(0 == hamming_distance(0, 0));
    // covers a == b
    assert(0 == hamming_distance(5, 5));
    // covers a >= && b >=0
    assert(2 == hamming_distance(0, 3));
    assert(1 == hamming_distance(0, 1));
    assert(1 == hamming_distance(1, 3));
    // covers a < 0 || b < 0
    assert(-1 == hamming_distance(-1, 0));
    assert(-1 == hamming_distance(4, -1));
    assert(-1 == hamming_distance(-1, -1));
    // covers a or b too large
    assert(-1 == hamming_distance(INT_MAX, 94321213123));
    assert(-1 == hamming_distance(342, INT_MAX));

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
    assert(binary(42949672900) != -1 );


    /*
        Testing power(int base, int exp) function  
    */
    assert(0 == power(0, 2));
    assert(4 == power(2, 2));
    assert(100 == power(10, 2));

    /*
        Testing sum_bits(long bin)
    */
    assert(2 == sum_bits(10001000));
    assert(0 == sum_bits(00000));
    assert(1 == sum_bits(100));

    /*
        Testing is_string_numeric(char *str) 
    */
    assert(1 == is_string_numeric("1234"));
    assert(1 == is_string_numeric("-213"));
    assert(1 == is_string_numeric("324 234"));
    assert(0 == is_string_numeric("213afea12"));
    assert(0 == is_string_numeric("2342-342"));

    /*
        Testing trim_trailing(char *str)
    */
    char str[] = " Hello World!";
    trim_trailing(str);
    assert(0 == strcmp(" Hello World!", str));
    char has_trailing[] = "234 abc       \n";
    trim_trailing(has_trailing);
    assert(0 != strcmp("234 abc       \n", has_trailing));

    
    printf("All tests passed!!\n");
    return 0;
}
