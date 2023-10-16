#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    /* code */
    _printf("The value : %c\n", 'X');
    _printf("The value : %i\n", 100);
    _printf("The value : %f\n", 100.42);
    _printf("The value : %s\n", "ibrahim");
    printf("%d\n", _printf("The value : %s\n", "ibrahim"));
    printf("%% test\n");
    return (0);
}
