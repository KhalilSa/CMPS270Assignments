#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "main_functions.h"

/*
    removes trailing whitespaces and newlines from a string
*/
void trim_trailing(char *str) {
    unsigned int index;
    index = strlen(str) - 1;
    while (index >=0 && isspace(str[index])) {
        str[index] = '\0';
        index--;
    }
}

/*
    Check if a string has only numeric, whitespace characters, and (-) character 
*/
int is_string_numeric(char *str) {
    int i = 0;
    // ignore first (-) character
    if (str[i] == '-') i++; 
    // check if the rest of the string has only 
    while (str[i] != '\0') {
        if (!isdigit(str[i]) && str[i] != ' ') return 0;
        i++;
    }

    return 1;
}

/*
    calulate the hamming distance between two positive integers
    preconditions:
        a : positive int
        b : positive int
        INT_MIN < a <= b < INT_MAX

    @returs the hamming distance between the two positive integers 
            if the preconditions are met, -1 otherwise
*/
int hamming_distance(int a, int b) {
    if (a < 0 || b < 0) return -1;
    if (a == b) return 0;
    if (a >= INT_MAX || b >= INT_MAX) return -1;
    // calculate a xor b
    unsigned int _xor = a ^ b;
    // convert a xor b to binary
    unsigned long bin_xor = binary(_xor);
    // count how many ones in bin_xor (same thing as summing all bits)
    int result = sum_bits(bin_xor);
    return result;
}

/*
    precondition: num is positive integer
    @return binary representation of the input integer
*/
unsigned long binary(unsigned int num) {
    unsigned long bin = 0;
    int exp = 0;
    while (num != 0) {
        int rem = num % 2;
        bin += rem * power(10, exp);

        num /= 2;
        exp++;
    }
    return bin;
}

unsigned long power(unsigned long base, unsigned int exp)
{
    unsigned long result = 1;
    while (exp > 0) {
        if ((exp & 1) == 1)
        {
            result = result * base;
        }
        base = base * base;
        exp = exp >> 1;
    }
    return result;
}
 

/*
    precondition: bin is a binary representation of a positive integer
    @returns the sum of all bits of the binary number (i.e counts the number of 1 bits)
*/
int sum_bits(unsigned long bin) {
    int count = 0;
    while (bin > 0) {
        count += bin % 2;
        bin /= 10;
    }
    return count;
}