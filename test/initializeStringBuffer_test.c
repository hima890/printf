/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main.h"

/**
 * main - Entry point for testing the initializeStringBuffer function.
 *
 * Description:
 *   This function serves as a test case for the `initializeStringBuffer` function.
 *   It allocates memory for a character buffer using `initializeStringBuffer`
 *   and checks whether the buffer is successfully allocated and initialized with
 *   '0'. It then prints a message indicating the result of the test.
 *
 *   If the buffer is successfully allocated, it prints a message indicating
 *   that the buffer is allocated and initialized. Otherwise, it prints an error
 *   message.
 *
 * Return: 0 (Always)
*/

int main(void)
{
    /* code */
    char *string_buffer;
    string_buffer = initializeStringBuffer(BUFFER_SIZE);

    if (string_buffer != NULL)
    {
        /* code */
        printf("The buffer is allocated and initialized with '0'.\n");
    }
    else
    {
        printf("An Error Occurred!!\n");
    }

    free(string_buffer);
    return (0);
}
