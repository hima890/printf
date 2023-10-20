#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
 * add0xPrefixToHex - Adds "0x" prefix to a given hexadecimal string.
 *
 * @hexString: The input hexadecimal string to which the "0x" prefix will be added.
 *
 * Description:
 *   This function takes an input hexadecimal string and returns a new string with "0x" added as a
 *   prefix to the original string. The resulting string is null-terminated. The function allocates
 *   memory for the new string and ensures it can accommodate the original string, "0x" prefix, and
 *   a null terminator.
 *
 * Return: A dynamically allocated string containing the original hexadecimal string with the "0x"
 *         prefix added, or NULL if the input string is NULL or on memory allocation failure.
*/
char *reverseString(const char *str)
{
    int length = strlen(str);
    int start;
    int end;

    char *reversed = (char *)malloc(length + 1);
    if (reversed == NULL) 
    {
        
        return (NULL);
    }

    start = 0;
    end = length - 1;

    while (start < length)
    {
        reversed[start] = str[end];
        start++;
        end--;
    }
    reversed[length] = '\0';

    return (reversed);
}
