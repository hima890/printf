#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
 * rot13 - Apply the ROT13 (rotate by 13 positions) algorithm to a given string.
 *
 * @str: The input string to be transformed using the ROT13 algorithm.
 *
 * Description:
 *   This function takes an input string and applies the ROT13 algorithm to it, which is a simple
 *   letter substitution cipher that replaces a letter with the 13th letter after it in the alphabet.
 *   It works for both uppercase and lowercase letters while leaving other characters unchanged.
 *   The function allocates memory for the result and returns a new string with the ROT13-transformed
 *   content. The result is null-terminated.
 *
 * Return: A dynamically allocated string containing the input string transformed using ROT13, or
 *         NULL if the input string is NULL or on memory allocation failure.
 */
char *rot13(const char *str)
{
    char *result = strdup(str);
    int i;
    char c;
    char base;
    if (result == NULL) {
        
        return (NULL);
    }

    for (i = 0; result[i]; i++)
    {
        c = result[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            base = (c >= 'A' && c <= 'Z') ? 'A' : 'a';
            result[i] = (c - base + 13) % 26 + base;
        }
    }

    return (result);
}
