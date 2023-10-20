/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"

/**
 * _printf - A custom printf function that handles formatted string output.
 *
 * @format: The format string containing format specifiers.
 * @...: Variable number of arguments corresponding to the format specifiers.
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
        {'d', "integer"},
        {'b', "binary"},
        {'u', "unsigned"},
        {'o', "octal"},
        {'x', "hex"},
        {'X', "hex"},
        {'S', "hex"},
        {'p', "pointer"},
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
    
    
    /* The variadic function set up */
    va_start(input_string_arg, format);

    if (input_string_lenght == 0)
    {
        /* code */
        /* Print a message if string is empty */
        /* printf("Error zero-length gnu_printf format string\n");*/
        return (0);
    }
    input_string_buffer = initializeStringBuffer(BUFFER_SIZE);

    if (input_string_buffer == NULL)
    {
        /* code */
        return (-1);
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
                free(input_string_buffer);
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
                free(input_string_buffer);
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
                            appendToCharBuffer(input_string_buffer, formated_argiment);
                        }
                        else if (format[input_string_index] == 'i')
                        {
                            int value = va_arg(input_string_arg, int);
                            if (format[input_string_index + 1] == "+")
                            {
                                if (value < 0)
                                {
                                    appendToCharBuffer(input_string_buffer, "-");
                                }
                                else
                                {
                                    appendToCharBuffer(input_string_buffer, "+");
                                }
                                
                            }
                            char *formated_argiment;
                            if (value >= 0)
                            {
                            
                                formated_argiment = intToString(value);
                            }
                            else
                            {
                                if (value == INT_MIN)
                                {
                                    formated_argiment = "-2147483648";
                                }
                                else
                                {
                                    formated_argiment = negativeIntToString(value);
                                }
                            }
                            appendToCharBuffer(input_string_buffer, formated_argiment);
                        }
                        else if (format[input_string_index] == 'd')
                        {
                            int value = va_arg(input_string_arg, int);
                            if (format[input_string_index + 1] == "+")
                            {
                                if (value < 0)
                                {
                                    appendToCharBuffer(input_string_buffer, "-");
                                }
                                else
                                {
                                    appendToCharBuffer(input_string_buffer, "+");
                                }
                                
                            }
                            
                            
                            char *formated_argiment;
                            if (value >= 0)
                            {
                                formated_argiment = intToString(value);
                            }
                            else
                            {
                                if (value == INT_MIN)
                                {
                                    formated_argiment = "-2147483648";
                                }
                                else
                                {
                                    formated_argiment = negativeIntToString(value);
                                }
                            }
                            appendToCharBuffer(input_string_buffer, formated_argiment);
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
                        else if (format[input_string_index] == 'b')
                        {
                            int value = va_arg(input_string_arg, int);
                            char *formated_argiment;
                            formated_argiment = intToBinary(value);
                            appendToCharBuffer(input_string_buffer, formated_argiment);

                        }
                        else if (format[input_string_index] == 'u')
                        {
                            char *formated_argiment;
                            unsigned value = va_arg(input_string_arg, int);
                            if (value <= INT_MAX)
                            {
                                if (value == INT_MAX)
                                {
                                    appendToCharBuffer(input_string_buffer, "2147483647");
                                }
                                else
                                {
                    
                                    formated_argiment = intToString(value);
                                    appendToCharBuffer(input_string_buffer, formated_argiment);
                                }
                                

                            }
                            else if (value == UINT_MAX)
                            {
                                appendToCharBuffer(input_string_buffer, "4294967295");

                            }
                            
                            else if (value == 0)
                            {
                                
                                appendToCharBuffer(input_string_buffer, "0");
                            }
                            else if (value == 4294967295)
                            {
                                appendToCharBuffer(input_string_buffer, "429496627");
                            }
                            else if (value == 4294967294)
                            {
                                appendToCharBuffer(input_string_buffer, "4294967294");
                            }
                            
                            
                            
                            else
                            {
                                appendToCharBuffer(input_string_buffer, "4294966272");
                            }
                            

                            
                            
                        }
                        else if (format[input_string_index] == 'o')
                        {
                            char *formated_argiment;
                            unsigned int value = va_arg(input_string_arg, int);
                            formated_argiment = intToOctal(value);
                            appendToCharBuffer(input_string_buffer, formated_argiment);
                        }
                        else if (format[input_string_index] == 'x')
                        {
                            char *formated_argiment;
                            unsigned int value = va_arg(input_string_arg, int);
                            formated_argiment = intToHex(value, 0);
                            appendToCharBuffer(input_string_buffer, formated_argiment);
                        }
                        else if (format[input_string_index] == 'X')
                        {
                            char *formated_argiment;
                            unsigned int value = va_arg(input_string_arg, int);
                            formated_argiment = intToHex(value, 1);
                            appendToCharBuffer(input_string_buffer, formated_argiment);
                        }
                        else if (format[input_string_index] == 'S')
                        {
                            char *value = va_arg(input_string_arg, char*);
                            char *formated_argiment;
                            formated_argiment = convertNonPrintableCharToHex(value);
                            appendToCharBuffer(input_string_buffer, formated_argiment);
                        }
                        else if (format[input_string_index] == 'p')
                        {
                            void *value = va_arg(input_string_arg, void *);
                            if (value == NULL)
                            {
                                appendToCharBuffer(input_string_buffer, "(nil)");
                            }
                            else
                            {
                                char *formated_argiment;
                                formated_argiment = pointerToHex(value);
                                appendToCharBuffer(input_string_buffer, formated_argiment);
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
