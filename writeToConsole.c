/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"


/**
 * writeToConsole - Writes the content of a character
 *  buffer to the standard output.
 *
 * @buffer: A pointer to the character buffer whose
 *  content will be written.
 *
 * Description:
 *   This function takes a pointer to a character
 *  buffer and writes its contents to
 *   the standard output (console) using the
 *  `write` system call. If the provided buffer
 *   is not NULL, the function will write the
 *  characters in the buffer to the console.
 *
 *   The `write` system call requires three
 * parameters: the file descriptor (in this case,
 *   `STDOUT_FILENO` represents the standard
 *  output), the buffer containing the data to
 *   write, and the number of bytes to write
 *  (determined by the length of the buffer).
 *
 *   If the provided buffer is NULL, the
 *  function print an error message.
 *
 *   This function is a simple way to
 *  display the contents of a buffer on the console without
 *   any formatting or additional content.
 *
 * Return: None
 */


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
/* printf("Error empty buffer\n"); */
}
}
