/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int input_string_lenght;
    int input_string_index;
    char *input_string_buffer; /* Pointer to the buffer */
    void *formated_argiment; /* Pointer To the  formated argiment */
    int typesLoop_index; /* Index for types structc loop */
    int dataType_index; /* Index for the types structc */
    int matchingFlag;
    va_list input_string_arg; /* Dec. the aruments list */

    /* Init. the vars valous */
    /* +1 to count the '\0' in the string lenght*/
    input_string_lenght = (strlen(format) + 1);
    input_string_index = 0;
    input_string_buffer = initializeStringBuffer(BUFFER_SIZE);

    /* The variadic function set up */
    va_start(input_string_arg, format);

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
                appendToCharBuffer(input_string_buffer, format[input_string_index]);
            
            }
            /* Check if its the end of the input string */
            else if (format[input_string_index] == '\0')
            {
                /* Write the content of the buffer to the main output and break the loop */
                writeToConsole(input_string_buffer);
                break;
            }
            
            
        }
        else /* If a specifier found */
        {
            input_string_index++; /* Incrise the charchter index after the "%" to get the specifier */
            /* Check for Valid specifier */
            if (isValid_specifier(format[input_string_index]) != NULL) /* If its not valid specifier */
            {   
                /* Print a message and break the loop */
                printf("Error not a valid specifier\n");
                break;
            }
            else /* If its valid specifier */
            {
                /* Get the corresponding argiment from the argiment list */
                /* Define an array of specifiers and their associated data types */
                type_list types[] = {
                    {'c', "char"},
                    {'i', "int"},
                    {'f', "float"},
                    {'s', "string"},
                    {0, NULL} /* Use 0 to indicate the end of the list */
                };

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
                        char formated_argiment = charcterFormating(value);
                        appendToCharBuffer(input_string_buffer, formated_argiment);
                    }
                    else if (format[input_string_index] == 'i')
                    {
                        int value = va_arg(input_string_arg, int);
                        char formated_argiment = integerFormating(value);
                        appendToCharBuffer(input_string_buffer, formated_argiment);
                    }
                    else if (format[input_string_index] == 'f')
                    {
                        double value = va_arg(input_string_arg, double);
                        char formated_argiment = deoubleFormating(value);
                        appendToCharBuffer(input_string_buffer, formated_argiment);                    
                    }
                    else if (format[input_string_index] == 's')
                    {
                        char *value = va_arg(input_string_arg, char *);
                        char formated_argiment = stringFormating(value);
                        appendToCharBuffer(input_string_buffer, formated_argiment);                       
                    }
                } 
                else
                {
                    printf("Unknown specifier: %c\n", format[input_string_index]);
                    break;
                }


                /* Write the content of the buffer to the main output and break the loop */
                writeToConsole(input_string_buffer);

                /* Incrise the charchter index after the specifier to get the next charchter */
                input_string_index++;

            }
            
        }
        
    }
    
    /* Free all the pionter */
    va_end(input_string_arg);
    free(input_string_buffer);

    /* Print a message if string is empty */
    printf("Error zero-length gnu_printf format string\n");
    /* A place holder for the total printed charchter */
    return (0); 
}
