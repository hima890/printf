#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * negativeIntToString - Converts an integer to a dynamically allocated string.
 *
 * @number: The integer to be converted to a string.
 *
 * Description:
 *   This function takes an integer and converts it
 *  into a dynamically allocated
 *   string. The resulting string contains the integer value in string format.
 *
 *   The function allocates memory for the string, ensuring it can accommodate
 *   the largest possible integer value plus a null-terminator.
 *
 *   If memory allocation fails, the function returns NULL.
 *
 * Return: A dynamically allocated string containing the integer as a string,
 *         or NULL on memory allocation failure.
*/
char *negativeIntToString(int number)
{
    char *result;
    int length = 0;
    long int temp = number;
    int i;
    while (temp != 0)
    {
        temp /= 10;
        length++;
    }

    if (number == 0)
    {
        length = 1;
    }
    result = (char *)malloc(length + 2);
    if (result == NULL)
    {
        return (NULL);
    }

    result[length + 1] = '\0';
    if (number < 0)
    {
        result[0] = '-';
        number = -number;
    }

    for (i = length; i >= (number < 0 ? 1 : 0); i--)
    {
        result[i] = (char)((number % 10) + '0');
        number /= 10;
    }
    result[0] = '-';
    return (result);
}