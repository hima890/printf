/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - A custom printf function that handles formatted string output.
 *
 * @input_string: The format string containing format specifiers.
 * @...: Variable number of arguments corresponding to the format specifiers.
 *
 * Description:
 *   This function provides custom printf-like functionality. It accepts a
 *   format string and a variable number of arguments, formats and converts
 *   the arguments according to the format specifiers in the string, and then
 *   prints the formatted result to the standard output.
 *
 *   Format specifiers are marked by '%' in the format string. The function
 *   supports the following format specifiers:
 *   - %c: for characters
 *   - %i: for integers
 *   - %f: for floating-point numbers
 *   - %s: for strings
 *
 *   If the format string contains an unsupported specifier, a message is
 *   printed, and the function terminates.
 *
 *   If the data type of the argument does not match the specifier, a message
 *   is printed, and the function terminates.
 *
 *   The function dynamically allocates and frees memory for a buffer to hold
 *   the formatted result.
 *
 * Return: None (void)
 */

int _printf(const char *format, ...)
{
    /* Dec. the vars names and types */
    /* The user sting input is stored in "input_string" */
    int numberOfCharacters_printed;
    int input_string_lenght;
    int input_string_index;
    char *input_string_buffer; /* Pointer to the buffer */
    int typesLoop_index;       /* Index for types structc loop */
    int dataType_index;        /* Index for the types structc */
    va_list input_string_arg;  /* Dec. the aruments list */
    /* Define an array of specifiers and their associated data types */
    type_list types[] = {
        {'c', "char"},
        {'i', "int"},
        {'f', "float"},
        {'s', "string"},
        {'d', "integer "},
        {0, NULL} /* Use 0 to indicate the end of the list */
    };

    if (format == NULL) {
        return (-1);
    }
    /* Init. the vars valous */
    /* +1 to count the '\0' in the string lenght*/
    numberOfCharacters_printed = 0;
    input_string_lenght = (strlen(format) + 1);
    input_string_index = 0;
    input_string_buffer = initializeStringBuffer(BUFFER_SIZE);
    
    /* The variadic function set up */
    va_start(input_string_arg, format);

    if (input_string_lenght == 0)
    {
        /* code */
        /* Print a message if string is empty */
        /* printf("Error zero-length gnu_printf format string\n");*/
        return (0);
    }

    /* Loop throght the charchters of the input_string */
    while (input_string_index < input_string_lenght)
    {
        /* Chech for a specifier */
        if (format[input_string_index] != '%') /* Check for normal charchter */
        {
            /* Check if its not the end of the input string */
            if (format[input_string_index] != '\0')
            {
                /* Append to the charchter to the buffer */
                appendToCharBuffer(input_string_buffer, charToString(format[input_string_index]));
            }
            /* Check if its the end of the input string */
            else if (format[input_string_index] == '\0')
            {
                /* Write the content of the buffer to the main output and break the loop */
                writeToConsole(input_string_buffer);
                numberOfCharacters_printed = strlen(input_string_buffer) + numberOfCharacters_printed;
                return (numberOfCharacters_printed);
            }
        }
        else /* If a specifier found */
        {
            /*printf("a specifier found\n");*/
            input_string_index++; /* Incrise the charchter index after the "%" to get the specifier */
            /*printf("The specifier is :%c\n", format[input_string_index]);*/
            if (format[input_string_index] == '\0')
            {
                return (-1);
            }
            

            if (format[input_string_index] != '%')
            {
                if (isValidSpecifier(format[input_string_index]) != true) /* If its not valid specifier */
                {
                    /*printf("not valid spicifier\n");*/
                    appendToCharBuffer(input_string_buffer, "%");
                    appendToCharBuffer(input_string_buffer, charToString(format[input_string_index]));
                }
                else /* If its valid specifier */
                {
                    /*printf("'%c' is a valid specifier\n", format[input_string_index]);*/

                    /* Initialize dataType_index with -1 to indicate no match */
                    dataType_index = -1;
                    /* Get the corresponding argiment from the argiment list */
                    /* Initialize dataType_index with -1 to indicate no match */
                    dataType_index = -1;

                    /* Loop to find the data type associated with the specifier */
                    for (typesLoop_index = 0; types[typesLoop_index].theSpicifier != 0; typesLoop_index++)
                    {
                        if (format[input_string_index] == types[typesLoop_index].theSpicifier)
                        {
                            dataType_index = typesLoop_index;
                            break;
                        }
                    }

                    if (dataType_index != -1)
                    {
                        /* Process the argument based on the determined data type */
                        if (format[input_string_index] == 'c')
                        {
                            char value = va_arg(input_string_arg, int);
                            char *formated_argiment = charToString(value);
                            if (value == '\0')
                            {
                                numberOfCharacters_printed++;
                            }
                            
                            appendToCharBuffer(input_string_buffer, formated_argiment);
                            free(formated_argiment);
                        }
                        else if (format[input_string_index] == 'i')
                        {
                            int value = va_arg(input_string_arg, int);
                            char *formated_argiment = intToString(value);
                            appendToCharBuffer(input_string_buffer, formated_argiment);
                            free(formated_argiment);
                        }
                        else if (format[input_string_index] == 'd')
                        {
                            int value = va_arg(input_string_arg, int);
                            char *formated_argiment = intToString(value);
                            appendToCharBuffer(input_string_buffer, formated_argiment);
                            free(formated_argiment);
                        }
                        else if (format[input_string_index] == 's')
                        {
                            char *charchter_holder = va_arg(input_string_arg, char *);
                            if (charchter_holder == NULL)
                            {
                                appendToCharBuffer(input_string_buffer, "(null)");
                            }
                            else
                            {
                                appendToCharBuffer(input_string_buffer, charchter_holder);
                            }
                            
                        }
                    }
                    else
                    {
                        /*printf("Unknown specifier: %c\n", format[input_string_index]);*/
                        break;
                    }
                }
            }
            else
            {
                /* Append to the charchter to the buffer */
                appendToCharBuffer(input_string_buffer, "%");
            }
        }

        input_string_index++; /* Incrise the charchter index after the "%" to get the specifier */
    }
    /* Free all the pionter */
    va_end(input_string_arg);
    free(input_string_buffer);
    

    /* A place holder for the total printed charchter */
    numberOfCharacters_printed++;
    return (numberOfCharacters_printed);
}
