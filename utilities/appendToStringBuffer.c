#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * appendToStringBuffer - Appends a string to an existing character buffer.
 *
 * @buffer: A pointer to the character buffer to which the string will be appended.
 * @str_to_append: The string that will be appended to the buffer.
 *
 * Description:
 *   This function takes an existing character buffer (allocated using `initializeStringBuffer`)
 *   and appends the specified string to it. It checks for valid input and available space
 *   in the buffer before appending. If there's enough space, the string is concatenated to the
 *   end of the buffer.
 *
 *   If either the `buffer` or `str_to_append` is `NULL`, the function returns the `buffer` as is.
 *
 *   If there's insufficient space in the buffer to append the string, you may choose to handle
 *   this situation accordingly. In this example, the function returns `NULL` to indicate an error.
 *
 *   The caller is responsible for managing memory, including freeing the buffer when it is
 *   no longer needed.
 *
 * Return: A pointer to the updated character buffer if the append operation is successful,
 *         or NULL in case of an error (e.g., insufficient space in the buffer).
 */

char *appendToStringBuffer(char *buffer, const char *str_to_append)
{
    if (buffer == NULL || str_to_append == NULL)
    {
        return buffer;
    }

    size_t buffer_len = strlen(buffer);
    size_t str_len = strlen(str_to_append);

    // Check if there's enough space to append the string
    if (buffer_len + str_len >= strlen(buffer))
    {
        // If not, you can choose to reallocate the buffer with more space
        // or return NULL to indicate an error.
        return NULL;
    }

    // Append the string to the buffer
    strcat(buffer, str_to_append);

    return buffer;
}