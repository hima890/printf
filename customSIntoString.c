#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "main.h"

/**
 * convertNonPrintableCharToHex - Converts a non-printable character to its hexadecimal representation.
 *
 * @inputString: The character to be converted.
 *
 * Description:
 *   This function takes a character as input and converts it to its hexadecimal representation.
 *   Non-printable characters (ASCII values less than 32 or greater than or equal to 127) are
 *   converted to the "\xXX" format, where "XX" represents the hexadecimal value of the character.
 *   Printable characters within the ASCII range are left as-is.
 *
 *   The function allocates memory for the output string and ensures it can accommodate the
 *   converted representation plus a null-terminator.
 *
 * Return: A dynamically allocated string containing the hexadecimal representation of the input character
 *         in the "\xXX" format, or the character itself if it is printable, or NULL on memory allocation failure.
*/
char *convertNonPrintableCharToHex(char *inputString)
{
    size_t inputLength;
    char *output;
    size_t i;
    int outputIndex;
    char inputChar;

    if (inputString == NULL) {
        return (NULL);
    }

    inputLength = strlen(inputString);

    output = (char *)malloc(10 * inputLength + 1);

    if (output == NULL) {
        return (NULL);
    }

    outputIndex = 0;

    for (i = 0; i < inputLength; i++) {
        inputChar = inputString[i];

        if (inputChar < 32 || inputChar >= 127) 
        {
            output[outputIndex++] = '\\';
            output[outputIndex++] = 'x';
            output[outputIndex++] = "0123456789ABCDEF"[(unsigned char)inputChar >> 4];
            output[outputIndex++] = "0123456789ABCDEF"[(unsigned char)inputChar & 0x0F];
        } else {
            output[outputIndex++] = inputChar;
        }
    }

    output[outputIndex] = '\0';

    return (output);
}
