#include <stdio.h>
#include <stdlib.h>

char *negativeIntToString(int number)
{
    char *result;
    int length = 0;
    long int temp = number;
    int i;
    while (temp != 0) {
        temp /= 10;
        length++;
    }

    if (number == 0) {
        length = 1;
    }
    result = (char *)malloc(length + 2);
    if (result == NULL) {
        return NULL;
    }

    result[length + 1] = '\0';
    if (number < 0) {
        result[0] = '-';
        number = -number;
    }

    for (i = length; i >= (number < 0 ? 1 : 0); i--) {
        result[i] = (char)((number % 10) + '0');
        number /= 10;
    }
    result[0] = '-';
    return result;
}

int main() {
    long int negativeNumber = -5551164968;
    char *result = negativeIntToString(negativeNumber);

    if (result != NULL) {
        printf("Converted: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
