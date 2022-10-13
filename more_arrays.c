#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_functions.c"
#include "main_functions.h"

int main() {
    const char *arr[][3] = {{"I", "LOVE", "CODING"}, {"THIS", "IS", "SPARTA"}};
    
    char **concat_arr = NULL;
    concat_arr = (char **) malloc(6 * sizeof(char*));

    concat_arr = concat(arr, 2);

    puts(concat_arr[0]);
    puts(concat_arr[1]);

    for (unsigned char i = 0; i < 2; i++) {
        free(concat_arr[i]);
    }
    free(concat_arr);

    return 0;
}