#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * charToString - Converts a character to a
 *  dynamically allocated string.
 *
 * @character: The character to be converted to a string.
 *
 * Description:
 *   This function takes a single character and
 *  converts it into a dynamically
 *   allocated string. The resulting string
 * contains the character followed by
 *   a null-terminator.
 *
 *   The function allocates memory for the
 * character and the null-terminator,
 *   and sets the character at the first
 * position in the string.
 *
 *   If memory allocation fails, the function returns NULL.
 *
 * Return: A dynamically allocated string
 * containing the character, or NULL on failure.
*/

char *charToString(char character)
{

char *string_pionter = (char *)malloc(2);
if (string_pionter == NULL)
{
return (NULL); /* Memory allocation failed */
}

string_pionter[0] = character; /* Set the character */
string_pionter[1] = '\0'; /* Null-terminate the string */

return (string_pionter);
}
