#include <stdbool.h>
#include <stdio.h>
#include "main.h"

/**
 * isValidSpecifier - Checks if a specifier character is valid.
 *
 * @specifier: The specifier character to be validated.
 *
 * Description:
 *   This function checks if the given specifier character
 *  is valid. It compares
 *   the character against a list of valid specifiers and
 * returns true if a match
 *   is found, indicating that the specifier is valid.
 *
 * Return: true if the specifier is valid, false otherwise.
 */

bool isValidSpecifier(const char specifier)
{
    int loopIndex;
    type_list specifiers[] = {
        {'c', "char"},
        {'i', "int"},
        {'f', "float"},
        {'s', "string"},
        {'d', "integer "},
        {'b', "binary"},
        {'u', "unsigned"},
        {'o', "octal"},
        {'x', "hex"},
        {'X', "hex"},
        {'S', "hex"},
        {'p', "pointer"},
        {'+', "flag"},
        {' ', "flag"},
        {'#', "flag"},
        {'r', "char *"},
        {'R', "char *"},
        {0, NULL} /* Use 0 to indicate the end of the list */
    };

    for (loopIndex = 0; specifiers[loopIndex].theSpicifier != 0; loopIndex++)
    {
        if (specifier == specifiers[loopIndex].theSpicifier)
        {
            return (true); /* Specifier is valid */
        }
    }
    return (false); /* Specifier is not valid */
}
