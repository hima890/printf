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

    buffer_len = strlen(buffer); /* The buffer lenght */
    str_len = (strlen(str_to_append) + 1); /* The string lenght pluse the the null-terminator */

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
        string_buffer = appendToStringBuffer(string_buffer, "Hello, world\n");
        if (string_buffer != NULL)
        {
            writeToConsole(string_buffer);
            free(string_buffer);
        }
    }

    return 0;
}
