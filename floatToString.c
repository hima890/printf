#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * floatToString - Converts a floating-point number
 * to a dynamically allocated string.
 *
 * @number: The floating-point number to be converted to a string.
 *
 * Description:
 *   This function takes a floating-point number and
 * converts it into a dynamically
 *   allocated string. The resulting string
 *  contains the floating-point number in
 *   string format.
 * Return: char charchter
 */
char *floatToString(float number)
{
/* Declare variables */
char *result;
int integerPart;
float fractionalPart;
int decimalPlaces = 6; /* You can adjust the number of decimal places */
int power;
int i  = 0;
int j;
int start = 1;
int end = i - 1;
result = (char *)malloc(64);

if (result == NULL)
{
return (NULL); /* Memory allocation failed */
}

/* Handle the sign */
if (number < 0)
{
result[0] = '-';
number = -number;
}
else
{
result[0] = ' ';
}

/* Convert the integer part to a string */
integerPart = (int)number;
i = 1; /* Start index for the string */

if (integerPart == 0)
{
result[i++] = '0';
}
else
{
while (integerPart > 0)
{
result[i++] = '0' + (integerPart % 10);
integerPart /= 10;
}

/* Reverse the integer part in the string */

while (start < end)
{
char temp = result[start];
result[start] = result[end];
result[end] = temp;
start++;
end--;
}
}

/* Add the decimal point */
result[i++] = '.';

/* Convert the fractional part to a string */
fractionalPart = number - (float)integerPart;
power = 1;

for (j = 0; j < decimalPlaces; j++)
{
int digit = (int)(fractionalPart *power);

power *= 10;
result[i++] = '0' + (digit % 10);
fractionalPart *= power;
}

/* Null-terminate the string */
result[i] = '\0';

return (result);
}
