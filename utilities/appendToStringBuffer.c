#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * appendToStringBuffer - Appends a string to an existing character buffer.
 *
 * @buffer: A pointer to the character buffer to which the string will be appended.
 * @str_to_append: The string that will be appended to the buffer.
 *
 * Description:
 *   This function takes an existing character buffer (allocated using `malloc` or similar)
 *   and appends the specified string to it. It checks for valid input and available space
 *   in the buffer before appending. If there's enough space, the string is concatenated to the end of the buffer.
 *
 *   If the `buffer` is `NULL`, the function returns the `buffer` as is.
 *
 *   If there's insufficient space in the buffer to append the string, the function reallocates
 *   the buffer and appends the string.
 *
 *   The caller is responsible for managing memory, including freeing the buffer when it is no longer needed.
 *
 * Return: A pointer to the updated character buffer if the append operation is successful,
 *         or NULL in case of an error in reallocation.
 */
char *appendToCharBuffer(char *buffer, const char *str_to_append)
{
    if (buffer == NULL)
    {
        return NULL;
    }

    size_t buffer_len = strlen(buffer);
    size_t str_len = strlen(str_to_append);

    char *new_buffer = (char *)realloc(buffer, buffer_len + str_len + 1); /* Allocate space for the string and null-terminator */

    if (new_buffer == NULL)
    {
        printf("Error: Memory reallocation failed\n");
        return NULL;
    }

    strcat(new_buffer, str_to_append); /* Append the string to the buffer */

    return new_buffer;
}
