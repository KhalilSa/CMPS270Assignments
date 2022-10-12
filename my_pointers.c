#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_functions.c"
#include "main_functions.h"

int main() {
    const char *arr1[] = {"ab", "ac", "zab"};
    const char *arr2[] = {"dd", "za", "zb", "zzzzc"};
    const size_t N1 = sizeof(arr1) / sizeof(char*);
    const size_t N2 = sizeof(arr2) / sizeof(char*);

    puts("Printing array 1:");
    print_array(arr1, N1);
    puts("Printing array 2:");
    print_array(arr2, N2);

    puts("Merging array 1 with array 2...");
    const size_t N3 = N1 + N2;
    char **arr3 = (char **) malloc(N3 * sizeof(char*));

    arr3 = merge(arr1, arr2, N1, N2);
    puts("Printing the result:");
    print_array((char*) arr3, N3);

    free(arr3);
    return 0;
}