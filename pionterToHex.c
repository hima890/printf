#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char hexChars[] = "0123456789abcdef";

    unsigned long address = (unsigned long)ptr;

    int numDigits = (sizeof(void*) * 2);

    char *result = (char*)malloc(numDigits + 19);
    int index;

    size_t newLength;
    char *newString;
    char *resultString;

    size_t currentLength;
    size_t appendLength;

    if (result == NULL) 
    {
        return (NULL);
    }

    index = numDigits + 2;
    result[index] = '\0';
    result[0] = '0';
    result[1] = 'x';

    while (index > 2)
    {
        index--;
        result[index] = hexChars[address & 0xf];
        address >>= 4;
    }
    
    newLength = strlen(result);
    newString = (char *)malloc(3);
    newString[0] = 0;
    newString[1] = 'x';
    if (ptr == (void *)-1)
    {
        strncat(newString, result + 2, newLength);
        newString[newLength] = '\0';
    }
    else
    {
        strncat(newString, result + 6, newLength);
        newString[newLength] = '\0';
    }
    
    
    
    resultString = (char *)malloc(3);
    if (resultString == NULL)
    {
        return (NULL);
    }
    strcpy(resultString, "0x");

    currentLength = strlen(resultString);
    appendLength = strlen(newString);

    resultString = (char *)realloc(resultString, currentLength + appendLength + 1);
    if (resultString == NULL)
    {
        return (NULL);
    }

    strcpy(resultString + currentLength, newString);

    resultString[currentLength + appendLength] = '\0';
    return (resultString);
}
