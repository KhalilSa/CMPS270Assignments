#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_functions.h"

/*
    concatenate strings of an array in a 2D array
    @param *arr[][3] 2D array of strings 
           N number of subarrays (rows):int 
    @returns 1D array of concatenated strings from 

*/
char** concat(const char *arr[][3], const unsigned int N) {
    char **result = (char**) malloc(N * sizeof(char*));
    const char *DELIMETER = " ";

    for (unsigned int i = 0; i < N; i++) {
        size_t memory_needed = 0;
        for (unsigned int j = 0; j < 3; j++) {
            memory_needed += strlen(arr[i][j]) + strlen(DELIMETER) + 1;
        }

        result[i] = (char *) malloc(memory_needed * (sizeof(char*)));
        for (unsigned int j = 0; j < 3; j++) {
            strcat(result[i], arr[i][j]);
            if (j != 2)
                strcat(result[i], DELIMETER);
        }
    }

    return result;
}

