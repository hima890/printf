#include <stdlib.h>
#include<string.h>
#include "main.h"
/**
 * addSignToString - Adds a sign character to the beginning of a string.
 *
 * @originalString: The original string to which the sign character will be added.
 * @sign: The sign character to be added.
 *
 * Description:
 *   This function takes an original string and a sign character as input and returns a new string
 *   in which the sign character is added to the beginning of the original string. The new string
 *   is null-terminated. The function allocates memory for the updated string and ensures it can
 *   accommodate the original string, the sign character, and a null terminator.
 *
 * Return: A dynamically allocated string containing the original string with the added sign character
 *         at the beginning, or NULL on memory allocation failure.
*/
char* addSignToString(const char* originalString, char sign)
{
    char* updatedString;

    size_t originalLength = strlen(originalString);
    size_t newLength = originalLength + 2;

    updatedString = (char *)malloc(newLength);

    if (updatedString == NULL)
    {
        return (NULL);
    }

    updatedString[0] = sign;
    strcpy(updatedString + 1, originalString);

    return (updatedString);
}