#include <stdio.h>
#include <stdlib.h>
#include "../main.h"



char* intToString(int number) {
    char* result = (char*)malloc(12); // Assuming a maximum of 12 characters for an int
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    snprintf(result, 12, "%d", number); // Convert int to string

    return result;
}

int main() {
    int num = 42;
    char* str = intToString(num);

    if (str != NULL) {
        printf("Integer as a string: %s\n", str);
        free(str); // Don't forget to free the allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
