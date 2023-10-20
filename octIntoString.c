#include <stdlib.h>
#include <limits.h>
#include "main.h"
/**
 * intToOctal - Converts an unsigned integer to its octal representation as a string.
 *
 * @value: The unsigned integer to be converted to octal.
 *
 * Description:
 *   This function takes an unsigned integer and converts it into its octal representation
 *   as a dynamically allocated string. The resulting string contains the octal digits (0-7)
 *   that represent the input integer.
 *
 *   The function calculates the number of octal digits required to represent the input value
 *   and allocates memory for the string to ensure it can accommodate the octal representation
 *   plus a null-terminator.
 *
 *   If memory allocation fails or if the input value is zero, the function returns "0" as a string.
 *
 * Return: A dynamically allocated string containing the octal representation of the unsigned integer,
 *         or "0" if the input value is zero, or NULL on memory allocation failure.
*/
char *intToOctal(unsigned int value)
{
    int digits = 0;
    unsigned int temp = value;
    char *octalString;
    int index;

    do {
        temp /= 8; 
        digits++;
    } while (temp != 0);

    if (digits == 0) {
        return ("0");
    }

    octalString = (char *)malloc(digits + 1);

    if (octalString == NULL)
    {
        return (NULL);
    }

    index = digits - 1;
    temp = value;

    do {
        octalString[index] = (temp % 8) + '0';
        temp /= 8;
        index--;
    } while (temp != 0);

    octalString[digits] = '\0';

    return (octalString);
}
