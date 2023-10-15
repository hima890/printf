/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../main.h"

bool containsStringSpecifier(const char *input)
{
    int loopIndex;
    int length;
    if (input == NULL)
    {
        /*to handle null input*/
        
        return (false);
    }

    length = strlen(input);
    for (loopIndex = 0; loopIndex < length; loopIndex++)
    {
        if (input[loopIndex] == '%')
        {
            if ((loopIndex + 1) < length)
            {
                char nextChar = input[loopIndex + 1];
                if (nextChar == 's' || nextChar == 'd' || nextChar == 'f' || nextChar == 'c')
                {
                    /* Check for known string specifiers like %s, %d, %f, %c, etc.*/
                    return (true);
                }
            }
        }
    }

    /*normal printing goes here*/
    return (false);
}
