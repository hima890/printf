#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * intToHex - Converts an unsigned integer to its hexadecimal representation as a string.
 *
 * @value: The unsigned integer to be converted to hexadecimal.
 * @flag: The flag for upper and low later
 * Description:
 *   This function takes an unsigned integer and converts it into its hexadecimal representation
 *   as a dynamically allocated string. The resulting string contains the hexadecimal digits
 *   (0-9, A-F) that represent the input integer.
 *
 *   The function calculates the number of hexadecimal digits required to represent the input value
 *   and allocates memory for the string to ensure it can accommodate the hexadecimal representation
 *   plus a null-terminator.
 *
 *   If memory allocation fails or if the input value is zero, the function returns "0" as a string.
 *
 * Return: A dynamically allocated string containing the hexadecimal representation of the unsigned integer,
 *         or "0" if the input value is zero, or NULL on memory allocation failure.
*/
char *intToHex(unsigned int value, int flag)
{
    int digits = 0;
    unsigned int temp = value;
    char *hexString;
    int index;

    do {
        temp /= 16;
        digits++;
    } while (temp != 0);

    if (digits == 0)
    {
        return ("0");
    }

    hexString = (char *)malloc(digits + 1);

    if (hexString == NULL) {
        return (NULL);
    }

    index = digits - 1;
    temp = value;

    do
    {
        int digit = temp % 16;
        if (flag != 1)
        {
            hexString[index] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);

        }
        else
        {
            hexString[index] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);

        }
        
        temp /= 16;
        index--;
    } while (temp != 0);

    hexString[digits] = '\0';

    return (hexString);
}
