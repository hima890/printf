#include <stdio.h>
#include <stdlib.h>
#include "../main.h"


char* floatToString(float number) {
    char* result = (char*)malloc(32); // Adjust the buffer size as needed
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    snprintf(result, 32, "%f", number); // Convert float to string

    return result;
}

int main() {
    float num = 3.14159;
    char* str = floatToString(num);

    if (str != NULL) {
        printf("Float as a string: %s\n", str);
        free(str); // Don't forget to free the allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
