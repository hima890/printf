#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * pointerToHex - Converts a pointer address to its hexadecimal representation.
 *
 * @ptr: The pointer whose address is to be converted.
 *
 * Description:
 *   This function takes a pointer as input and converts its address to its hexadecimal representation.
 *   The address is formatted in the "0xXXXXXXXXXXXXXXXX" format, where "X" represents a hexadecimal digit.
 *   The function allocates memory for the output string and ensures it can accommodate the converted address
 *   plus a null-terminator.
 *
 * Return: A dynamically allocated string containing the hexadecimal representation of the input pointer's address
 *         in the "0xXXXXXXXXXXXXXXXX" format, or NULL on memory allocation failure.
 */
char *pointerToHex(void *ptr)
{
    char *output = (char *)malloc(15);
    unsigned long  address;
    int i;
    int digit;

    if (output == NULL) {
        return (NULL);
    }

    address = (unsigned long)ptr;
    output[0] = '0';
    output[1] = 'x';

    
    for (i = 15; i >= 2; i--)
    {
        digit = (address >> (i * 4)) & 0xF;
        output[17 - i] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    }

    output[14] = '\0';

    return (output);
}
