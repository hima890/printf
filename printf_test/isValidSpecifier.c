#include <stdbool.h>
#include <stdio.h>
#include "main.h"


bool isValidSpecifier(const char specifier){
    int loopIndex;
    type_list specifiers[] = {
        {'c', "char"},
        {'i', "int"},
        {'f', "float"},
        {'s', "string"},
        {0, NULL} /* Use 0 to indicate the end of the list */
    };

    for (loopIndex = 0; specifiers[loopIndex].theSpicifier != 0; loopIndex++) {
        if (specifier == specifiers[loopIndex].theSpicifier)
        {
            return (true); /* Specifier is valid */
        }
    }
    return (false);  /* Specifier is not valid */
}
