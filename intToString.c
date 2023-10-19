#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * intToString - Converts an integer to a dynamically allocated string.
 *
 * @number: The integer to be converted to a string.
 *
 * Description:
 *   This function takes an integer and converts it
 *  into a dynamically allocated
 *   string. The resulting string contains the integer value in string format.
 *
 *   The function allocates memory for the string, ensuring it can accommodate
 *   the largest possible integer value plus a null-terminator.
 *
 *   If memory allocation fails, the function returns NULL.
 *
 * Return: A dynamically allocated string containing the integer as a string,
 *         or NULL on memory allocation failure.
*/

char *intToString(int number)
{
int temp = number;
int length = 0;
char *result;
int loopIndex;

if (temp == 0)
{
length = 1;/* Special case for zero */
}
else
{
while (temp != 0)
{
temp /= 10;
length++;
}
}

/* Allocate memory for the string (including space for null-terminator) */
result = (char *)malloc(length + 1);
if (result == NULL)
{
return (NULL); /* Memory allocation failed */
}

/* Convert the integer to a string manually */
result[length] = '\0'; /* Null-terminate the string */
if (number == 0)
{
result[0] = '0'; /* Special case for zero */
}
else
{
int isNegative = 0;
if (number < 0)
{
isNegative = 1;
number = -number;
}
for (loopIndex = length - 1; loopIndex >= 0; loopIndex--)
{
result[loopIndex] = (char)((number % 10) + '0');
number /= 10;
}
if (isNegative)
{
result[0] = '-'; /* Add a minus sign for negative numbers */
}
}

return (result);

}
