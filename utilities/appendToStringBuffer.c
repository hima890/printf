/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main.h"

/**
 * appendToStringBuffer - Appends a string to an existing character buffer.
 *
 * @buffer: A pointer to the character buffer to which the string will be appended.
 * @str_to_append: The string that will be appended to the buffer.
 *
 * Description:
 *   This function takes an existing character buffer (allocated using `initializeStringBuffer`)
 *   and appends the specified charchter to it. It checks for valid input and available space
 *   in the buffer before appending. If there's enough space, the string is concatenated to the
 *   end of the buffer.
 *
 *   If the `buffer` is `NULL`, the function returns the `buffer` as is.
 *
 *   If there's insufficient space in the buffer to append the character the function relocted the buffer and append the character.
 *
 *   The caller is responsible for managing memory, including freeing the buffer when it is
 *   no longer needed.
 *
 * Return: A pointer to the updated character buffer if the append operation is successful,
 *         or NULL in case of an error in relocted.
 */

char *appendToCharBuffer(char *buffer, char char_to_append)
{
    /* Vars Dec. */
    size_t buffer_len;
    char *new_buffer; /* Pointer to the relocated buffer */

    /* Check for the buffer */
    if (buffer == NULL)
    {
        /* Return the same buffer content as it is */
        return buffer;
    }

    buffer_len = strlen(buffer); /* The buffer length */

    /* Check if there's enough space to append the character */
    if (buffer_len + 1 >= strlen(buffer))
    {
        /* Not enough space, so reallocate the buffer */
        size_t new_size = buffer_len + 1;  /* New buffer size */
        new_buffer = (char *)realloc(buffer, new_size); /* Allocate the relocated buffer */

        /* Check for the relocated buffer */
        if (new_buffer == NULL)
        {
            /* If the relocation fails, print a message and return null */
            printf("Error: Memory reallocation failed\n");
            return NULL;
        }

        /* Set the buffer pointer to the new relocated buffer */
        buffer = new_buffer;
    }

    /* Append the character to the buffer */
    buffer[buffer_len] = char_to_append;
    buffer[buffer_len + 1] = '\0'; // Null-terminate the string

    /* Return the buffer pointer */
    return buffer;
}
