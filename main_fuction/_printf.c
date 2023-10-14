#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../header/main.h"

void copyString(char *dest, const char *src);

/**
 * _printf - a mimc to the real printf function
 * @format: the formated string
 *
 * Return:the formated string

*/

int _printf(const char *format, ...)
{

    int bytesWritten;
    /*creating a string buffer of size 1024 bytes*/
    char stringbuffer[1024];
    /*using the string copy function to get the data from the parameter to the buffer*/
    copyString(stringbuffer, format);
    /*Write the string to the standard output (console)*/
    bytesWritten = write(STDOUT_FILENO, stringbuffer, strlen(stringbuffer));
}

/*the main function is only for testing*/
int main()
{
    _printf("Hello");

    return (0);
}

/**
 * copyString - a function that copies a string form
 *              the parameter to the string buffer
 * @dest:the destination "the buffer"
 * @src:the source "the parameter"
 * Return: nothing function is of type void
 */

void copyString(char *dest, const char *src)
{
    strcpy(dest, src);
}