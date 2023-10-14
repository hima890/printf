PRINTF(3)                 Linux Programmer's Manual                PRINTF(3)

NAME
       my_printf - mimic the C language printf function

SYNOPSIS
       #include <my_printf.h>

       int my_printf(const char *format, ...);

DESCRIPTION
       The my_printf() function mimics the behavior of the C language printf
       function. It formats and prints output based on the format specifier
       in the 'format' string.

       This function supports various format specifiers, such as %s for
       strings, %d for integers, %f for floating-point numbers, and more.
       It also supports width and precision specifiers.

RETURN VALUE
       The my_printf() function returns the number of characters printed
       (excluding the null-terminating character).

EXAMPLES
       Example 1: Basic usage

           #include <my_printf.h>
           ...
           int main() {
               int number = 42;
               char *text = "Hello, World!";
               int printed = my_printf("Number: %d, Text: %s\n", number, text);
               ...
           }

       Example 2: Using format specifiers

           #include <my_printf.h>
           ...
           int main() {
               float pi = 3.14159;
               int width = 10;
               int precision = 2;
               int printed = my_printf("Pi: %*.2f\n", width, pi);
               ...
           }

SEE ALSO
       printf(3), man(1)

AUTHOR
       Your Name

REPORTING BUGS
       Report bugs to your@email.com.

COPYRIGHT
       This is free software; you can redistribute it and/or modify it under
       the terms of the MIT License.

https://www.linkedin.com/in/ibrahim-hanafi-1a21b5174https://www.facebook.com/ibrahim.hanafi.925?mibextid=ZbWKwL
