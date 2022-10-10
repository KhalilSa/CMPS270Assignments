#include <stdio.h>
#include "main_functions.c"

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

