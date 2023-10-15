/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../main.h"

char *initializeStringBuffer(int buffer_size)
{
    char *buffer_pointer;

    if (buffer_size <= 0)
    {
        printf("Error: Invalid buffer size\n");
        return NULL;
    }

    buffer_pointer = (char *)malloc(sizeof(char) * buffer_size);
    if (buffer_pointer == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    memset(buffer_pointer, 0, buffer_size);
    return buffer_pointer;
}


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


void writeToConsole(const char *buffer)
{
    /* Check for the buffer content */
    if (buffer != NULL)
    {
        /* Write to the std output file "Terminal" */
        write(STDOUT_FILENO, buffer, strlen(buffer));
    }
    else
    {
        /* Write un error message */
        printf("Error empty buffer\n");
    }
}


int main(void)
{
    char *string_buffer;

    string_buffer = initializeStringBuffer(5); /* Use the defind buffor */
    if (string_buffer != NULL)
    {
        string_buffer = appendToCharBuffer(string_buffer, 'h');
        if (string_buffer != NULL)
        {
            writeToConsole(string_buffer);
            free(string_buffer);
        }
    }

    return 0;
}
