#include <stdio.h>
#include <stdlib.h>

char* charToString(char character) {
    char* str = (char*)malloc(2); // Allocate memory for the character and null-terminator
    if (str == NULL) {
        return NULL; // Memory allocation failed
    }

    str[0] = character; // Set the character
    str[1] = '\0'; // Null-terminate the string

    return str;
}

int main() {
    char c = 'A';
    char* str = charToString(c);

    if (str != NULL) {
        printf("Character as a string: %s\n", str);
        free(str); // Don't forget to free the allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
