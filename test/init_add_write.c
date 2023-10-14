/* Header files go here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
    if (buffer == NULL || str_to_append == NULL)
    {
        return buffer;
    }

    size_t buffer_len = strlen(buffer);
    size_t str_len = strlen(str_to_append);

    // Check if there's enough space to append the string
    if (buffer_len + str_len >= strlen(buffer))
    {
        // Not enough space, so reallocate the buffer
        size_t new_size = buffer_len + str_len + 1;  // +1 for the null-terminator
        char *new_buffer = (char *)realloc(buffer, new_size);
        if (new_buffer == NULL)
        {
            printf("Error: Memory reallocation failed\n");
            return NULL;
        }
        buffer = new_buffer;
    }

    // Append the string to the buffer
    strcat(buffer, str_to_append);

    return buffer;
}

void writeToConsole(const char *buffer)
{
    if (buffer != NULL)
    {
        write(STDOUT_FILENO, buffer, strlen(buffer));
    }
}

int main(void)
{
    char *string_buffer;

    string_buffer = initializeStringBuffer(80);
    if (string_buffer != NULL)
    {
        string_buffer = appendToStringBuffer(string_buffer, "Hello, world");
        if (string_buffer != NULL)
        {
            writeToConsole(string_buffer);
            free(string_buffer);
        }
    }

    return 0;
}
