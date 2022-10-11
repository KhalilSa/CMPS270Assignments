#include <stdio.h>
#include <stdlib.h>
#include "main_functions.h"

/*
    takes 1D integer array and its size, then prints a table of index-value pairs
    preconditions:
        arr: an initialized integer array
        N: a positive integer representing the real size of the array
*/
void printArray(int *arr, const unsigned int N) {
    if (arr == NULL || N <= 0) {
        printf("Nothing to print\n");
        return;
    }

    printf("Index Value\n");
    for (unsigned int i = 0; i < N; i++) {
        printf("%5d %5d\n", i, arr[i]);
    }
}

/*
    takes 1D integer array and its size, then prints a histogram for element frequencies
    preconditions:
        arr: an initialized integer array
        N: a positive integer representing the real size of the array
*/
void arrayHistogram(int *arr, const unsigned int N) {
    if (arr == NULL || N <= 0) {
        printf("Nothing to print\n");
        return;
    }

    int visited[N][2];

    // copy arr elements to visited arr
    // mark all elements as unvisited
    for (unsigned int i = 0; i < N; i++) {
        visited[i][0] = arr[i];
        visited[i][1] = 0;
    }

    printf("Value Frequence Histogram\n");
    // traverse the array and count the frequencies
    for (unsigned int i = 0; i < N; i++) {
        // ignore visited elements
        if (visited[i][1] == 1) continue;

        // count frequency
        unsigned int count = 1;
        for (unsigned int j = i + 1; j < N; j++) {
            if (arr[i] == arr[j]) {
                // mark the element as visited
                visited[j][1] = 1;
                count++;
            }
        }

        // store the frequency as a string of *
        char *freq = ((char *) calloc(count, 1));
        for (unsigned int f = 0; f < count; f++) {
            freq[f] = '*';
        }
        // print the histogram
        printf("%5d %9d %9s\n", arr[i], count, freq);
        free(freq);

    }
}

/*
    takes an array and two indices, then swaps the values at those positions
    preconditions:
        arr: an initialized integer array
        N: a positive integer representing the real size of the array
        i, j = positive integers less than the length of the array
*/
void swapValues(int *arr, const unsigned int N, int i, int j) {
    if (arr == NULL || N <= 0) {
        puts("ERROR: Can't swap array of NULL.");
        return;
    }

    if (i >= N || j >= N) {
        puts("ERROR: i or j is out of bound.");
        return;
    }

    // no need for swapping
    if (arr[i] == arr[j]) return;

    // swapping the values of i and j
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
    takes an array of integers and performs in-place bubble sort 
    preconditions:
        arr: an initialized integer array
        N: a positive integer representing the real size of the array
    @returns a sorted array in ascending order
*/
void bubbleSort(int* arr, const unsigned int N) {
    if (arr == NULL || N <= 1) return;

    for (unsigned int i = 0; i < N; i++) {
        for (unsigned int j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                swapValues(arr, N, i, j);
            }
        }
    }
}

/*
    takes an array of integers and calculates the median
    preconditions:
        arr: an initialized integer array
        N: a positive integer representing the real size of the array
    @returns the median of the list :double
*/
float median(int *arr, const unsigned int N) {
    if (arr == NULL || N <= 0) return 0;
    
    // copy array elements
    // So not to manipulate the original array
    int copy[N];
    for (unsigned int i = 0; i < N; i++) {
        copy[i] = arr[i];
    }

    // sort the copy array
    bubbleSort(copy, N);

    // pick the middle element
    if (N % 2 == 0) {
        return (copy[(int) (N/2)] + copy[(int) (N/2)-1]) / 2.0;
    }

    return copy[(int) (N/2)];
}

