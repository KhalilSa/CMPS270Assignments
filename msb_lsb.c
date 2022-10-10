#include <stdio.h>
#include <stdlib.h>
#include "main_functions.c"
#include "main_functions.h"

int main() {
    long num;
    char input[MAX_LINE];
    
    printf("     (Enter a positive non-zero integer)    \n");
    while(1) {
        printf("Input: ");
        fgets(input, sizeof(input), stdin);
        trim_trailing(input);
        int valid = is_string_numeric(input);
        if (!valid) {
            printf("ERROR: Invalid Input (Only positive non-zero Integers Are Allowed)\n");
            continue;
        }
        num = atol(input);
        if (num <= 0) {
            printf("Invalid Input: please enter a non-zero positive integer\n");
            continue;
        }
        break;
    };
    printf("%d in binary: %lu\n", num, binary(num));
    printf("Output: %d\n", msb_lsb_diff(msb(num), lsb(num)));
    return 0;
}