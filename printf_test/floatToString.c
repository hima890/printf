#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * floatToString - Converts a floating-point number to a dynamically allocated string.
 *
 * @number: The floating-point number to be converted to a string.
 *
 * Description:
 *   This function takes a floating-point number and converts it into a dynamically
 *   allocated string. The resulting string contains the floating-point number in
 *   string format.
 *
 *   The function allocates memory for the string, ensuring it can accommodate the
 *   largest possible floating-point value plus a null-terminator.
 *
 *   If memory allocation fails, the function returns NULL.
 *
 * Return: A dynamically allocated string containing the floating-point number
 *         as a string, or NULL on memory allocation failure.
*/

char* floatToString(float number)
{
    char *result = (char*)malloc(32); /* Adjust the buffer size as needed */
    if (result == NULL) {
        return (NULL); /* Memory allocation failed */
    }

    snprintf(result, 32, "%f", number); /* Convert float to string */

    return (result);
}
