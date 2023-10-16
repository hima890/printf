/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * copyString - copy string
 * @dest: the buffer to copy to
 * @src: what to copy
*/
void copyString(char *dest, const char *src)
{
strcpy(dest, src);
}
