#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    /* code */
    /* Test the data types*/
    
    _printf("The value : %c\n", 'X');
    _printf("The value : %i\n", 100);
    _printf("The value : %f\n", 100.42);
    _printf("The value : %s\n", "ibrahim");
    

   /*Test the number of characters printed
    printf("%d\n", _printf("A test\n"));
    printf("%d\n", printf("A test\n"));

    */

    /*
   int _return;
   _return = printf("Unknown:[%v]\n");
   printf("%d\n", _return);

    _return = _printf("Unknown:[%v]\n");
    printf("%d\n", _return);
    */
    return (0);
}
