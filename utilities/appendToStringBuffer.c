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
    /* Vars Dec. */
    size_t buffer_len;
    size_t str_len;
    char *new_buffer; /* Pointer to the relocted buffer */

    /* Check for buffer and the string */
    if (buffer == NULL || str_to_append == NULL)
    {
        /* Return the same buffer contect as it is */
        return buffer;
    }

    size_t buffer_len = strlen(buffer); /* The buffer lenght */
    size_t str_len = (strlen(str_to_append) + 1); /* The string lenght pluse the the null-terminator */

    /*Check if there's enough space to append the string*/ 
    if (buffer_len + str_len >= strlen(buffer))
    {
        /* Not enough space, so reallocate the buffer*/
        size_t new_size = buffer_len + str_len;  /* New buffer size */
        new_buffer = (char *)realloc(buffer, new_size); /* Assigned the relocted buffer to pionter */

        /* Check for the relocted buffer */
        if (new_buffer == NULL)
        {
            /* If the relocted faild print a message and retunt null */
            printf("Error: Memory reallocation failed\n");
            return NULL;
        }

        /* Set the buffer pionter to the new relocted buffer */
        buffer = new_buffer;
    }

    /* Append the string to the buffer*/
    strcat(buffer, str_to_append);

    /* Return the buffer pointer */
    return buffer;
}
