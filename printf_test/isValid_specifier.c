/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../main.h"

/**
 * containsStringSpecifier - Checks if a string contains format specifiers.
 *
 * @input: The input string to check for format specifiers.
 *
 * Description:
 *   This function examines the input string to determine if it contains any
 *   format specifiers. Format specifiers are denoted by the '%' character
 *   followed by a valid specifier character, such as 's', 'd', 'f', or 'c'.
 *
 *   If the input string contains one or more valid format specifiers, the
 *   function returns true; otherwise, it returns false.
 *
 *   If the input is NULL, the function returns false to handle this case.
 *
 * Return: true if the string contains valid format specifiers, false otherwise.
*/

bool containsStringSpecifier(const char *input)
{
    int loopIndex;
    int length;
    if (input == NULL)
    {
        /*to handle null input*/
        
        return (false);
    }

    length = strlen(input);
    for (loopIndex = 0; loopIndex < length; loopIndex++)
    {
        if (input[loopIndex] == '%')
        {
            if ((loopIndex + 1) < length)
            {
                char nextChar = input[loopIndex + 1];
                if (nextChar == 's' || nextChar == 'd' || nextChar == 'f' || nextChar == 'c')
                {
                    /* Check for known string specifiers like %s, %d, %f, %c, etc.*/
                    return (true);
                }
            }
        }
    }

    /*normal printing goes here*/
    return (false);
}
