#ifndef main_functions

#define main_functions
#include <stddef.h>
#define SIZE 10

void print_array(const char *arr[], const size_t N);
void print_2d_array(const char *arr[][3], const size_t N, const size_t M );
char** concat(const char *arr[][3], const unsigned int N);

#endif