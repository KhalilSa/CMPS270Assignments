#include <stdio.h>
#include "main_functions.c"
#include "main_functions.h"

int main() {
    int arr[SIZE] = {1, 3, 2, 1, 3, 1, 1, 2, 1, 2};
    printArray(arr, SIZE);
    arrayHistogram(arr, SIZE);
    swapValues(arr, SIZE, 11, 0);
    swapValues(arr, SIZE, 1, 0);
    printArray(arr, SIZE);
    printf("Median: %.2f\n", median(arr, SIZE));
    bubbleSort(arr, SIZE);
    printf("Sort Array:\n");
    printArray(arr, SIZE);
    return 0;
}