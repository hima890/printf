#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool containsStringSpecifier(const char* input) {
    if (input == NULL) {
        /*To handel NUll input*/
        return false;
    }

    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (input[i] == '%') {
            if (i + 1 < length && (input[i + 1] == 's' || input[i + 1] == 'd' || input[i + 1] == 'f' || input[i + 1] == 'c')) {
                /* Check for known string specifiers like %s, %d, %f, %c, etc.*/
                
                
                /*Code to handle the string specificer goes here*/
                return true;
            }
        }
    }
    /*normal printing goes here*/
    return false;
}
