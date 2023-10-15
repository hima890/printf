#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * intToString - Converts an integer to a dynamically allocated string.
 *
 * @number: The integer to be converted to a string.
 *
 * Description:
 *   This function takes an integer and converts it into a dynamically allocated
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

char *intToString(int number) {
    char* result = (char*)malloc(12); /* Assuming a maximum of 12 characters for an int */
    if (result == NULL)
    {
        return (NULL); /* Memory allocation failed */
    }

    snprintf(result, 12, "%d", number); /* Convert int to string */

    return (result);
}
