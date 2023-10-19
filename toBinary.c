#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * intToBinary - Converts an integer to its binary representation as a string.
 *
 * @number: The integer to be converted to binary.
 *
 * Description:
 *   This function takes an integer and converts it into its binary representation
 *   as a dynamically allocated string. The resulting string contains the binary
 *   digits (0s and 1s) that represent the input integer.
 *
 *   The function allocates memory for the string, ensuring it can accommodate the
 *   binary representation of the input integer plus a null-terminator.
 *
 *   If memory allocation fails, the function returns NULL.
 *
 * Return: A dynamically allocated string containing the binary representation
 *         of the integer, or NULL on memory allocation failure.
 */
char *intToBinary(int number)
{
    int bits = sizeof(number) * 8;
    int i;
    char *firstOne;
    char *result;
    char *binary = (char *)malloc(bits + 1);

    if (binary == NULL)
    {
        return NULL;
    }

    binary[bits] = '\0';

    for (i = bits - 1; i >= 0; i--)
    {
        binary[i] = (number & 1) ? '1' : '0';
        number >>= 1;
    }

    firstOne = strchr(binary, '1');

    result = firstOne != NULL ? strdup(firstOne) : strdup("0");

    free(binary);

    return result;
}
