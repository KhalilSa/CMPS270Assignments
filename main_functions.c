#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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
    Check if a string has only numeric character
    @returns 1 if the string is numeric
             0 otherwise
*/
int is_string_numeric(char *str) {
    int i = 0;
    // check if the rest of the string includes only digits
    while (str[i] != '\0') {
        if (!isdigit(str[i])) return 0;
        i++;
    }

    return 1;
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
        bin += rem * (unsigned long) pow(10, exp);

        num /= 2;
        exp++;
    }
    return bin;
}

int msb(unsigned int num) {
    if (num == 0) return -1;
    unsigned long bin = binary(num);
    return floor(log10(bin));
}

int lsb(unsigned int num) {
    if (num == 0) return -1;
    unsigned long bin = binary(num);
    int index = 0;
    while (bin != 0) {
        if (bin % 2 == 1)
            return index;
        bin /= 2;
        index++;
    }
    return -1;
}

/*
    takes two positive integers and calculates the difference
    precondition: msb >= lsb

    @returns the difference between msb and lsb
*/
int msb_lsb_diff(int msb, int lsb) {
    if (msb < 0 || lsb < 0) return -1;
    return msb - lsb;
}