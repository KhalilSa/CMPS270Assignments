#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hamming_distance.h"

int main() {
    int a, b;
    char input[MAX_LINE];
    printf("     (Enter a negative integer to terminate)    \n");
    while(1) {
        printf("Enter a pair of positive integers: ");
        fgets(input, sizeof(input), stdin);
        trim_trailing(input);
        int valid = is_string_numeric(input);
        if (!valid) {
            printf("ERROR: Invalid Input (Only Integers Are Allowed)\n");
            continue;
        }
        // split the string at whitespaces
        char *token = strtok(input, " ");
        // get the first number
        a = atoi(token);
        // stop the program if the user enters a negative number
        if (a < 0) break;
        // get the second number
        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("ERROR: You need to enter TWO positive integers\n");
            continue;
        }
        b = atoi(token);
        int dist = hamming_distance(a, b);
        printf("%d\n", dist);
    };
    return 0;
}

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

int hamming_distance(int a, int b) {
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
long binary(unsigned int num) {
    long bin = 0;
    while (num > 0) {
        bin *= 10;
        bin += num % 2;
        num /= 2;
    }
    return bin;
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
