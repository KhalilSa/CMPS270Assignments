#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_functions.h"

/*
    takes 1D an array of strings (character arrays) 
    and its size, then prints each string in a new line
    preconditions:
        arr: an initialized integer array
        N: a positive integer representing the real size of the array
*/
void print_array(const char *arr[], const size_t N) {
    if (arr == NULL || N == 0) {
        printf("Nothing to print\n");
        return;
    }
    
    for (unsigned int i = 0; i < N; i++) {
        puts(arr[i]);
    }
}

/*
    takes 2 sorted (lexiographically) arrays of strings (a.k.a two arrays of character arrays)
    then concatenate the two together into one array of strings
    while perserving the alpha-numeric order 

    preconditions:
        arr1: an initialized character array
        arr2: an initialized character array
        N1: a positive integer representing the real size of arr1
        N2: a positive integer representing the real size of arr2

    @returns merged sorted array, NULL if both arrays are NULL
*/
char **merge(const char *arr1[], const char *arr2[], const size_t N1, const size_t N2) {
    if (arr1 == NULL && arr2 == NULL) return NULL;
    unsigned int i = 0, j = 0;
    // create enough space for an array of size N1 + N2
    const size_t N3 = N1 + N2;
    char **result = NULL;
    result = (char **) malloc(N3 * sizeof(char*));

    // Loop until one array ends
    while ( i < N1 && j < N2) {
        // initialize empty space for the string
        // then copy the element that comes first lexigraphically
        if (strcmp(arr1[i], arr2[j]) <= 0) {
            result[i+j] = (char *) (malloc((strlen(arr1[i]) + 1) * sizeof(char)));
            strcpy(result[i+j], arr1[i]);
            i++;
        } else {
            result[i+j] = (char *) (malloc((strlen(arr2[j]) + 1) * sizeof(char)));
            strcpy(result[i+j], arr2[j]);
            j++;
        }
    }

    // copy remaining strings from arr1 if any
    while (i < N1) {
        result[i+j] = (char *) (malloc((strlen(arr1[i]) + 1) * sizeof(char)));
        strcpy(result[i+j], arr1[i]);
        i++;
    }

    // copy remaining strings from arr2 if any
    while (j < N2) {
        result[i+j] = (char *) (malloc((strlen(arr2[j]) + 1) * sizeof(char)));
        strcpy(result[i+j], arr2[j]);
        j++;
    }

    return result;
} 