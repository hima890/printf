/* Header files goes here */
#include "../printf/main.h"




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
    void *corresponding_argiment; /* Pointer To the corresponding argiment */
    void *formated_argiment; /* Pointer To the  formated argiment */

    /* Ini. the vars valous */
    /* +1 to count the '\0' in the string lenght*/
    input_string_lenght = (strlen(format) + 1);
    input_string_index = 0;
    input_string_buffer = initializeStringBuffer(BUFFER_SIZE);

    /* The variadic function set up */
    va_list input_string_arg;
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
                append_inputString_to_theBuffer(format[input_string_index]);
            
            }
            /* Check if its the end of the input string */
            else if (format[input_string_index] == '\0')
            {
                /* Write the content of the buffer to the main output and break the loop */
                write_theBuffer_toStdOutput();
                break;
            }
            
            
        }
        else /* If a specifier found */
        {
            input_string_index++; /* Incrise the charchter index after the "%" to get the specifier */
            /* Check for Valid specifier */
            if (isValid_specifier(format[input_string_index]) != 1) /* If its not valid specifier */
            {   
                /* Print a message and break the loop */
                printf("Error not a valid specifier\n");
                break;
            }
            else /* If its valid specifier */
            {
                /* Get the corresponding argiment from the argiment list */
                corresponding_argiment = findTheCorresponding_argiment(format[input_string_index], input_string_arg);

                /* Check of the argument data type match thespecifier */
                if (isArgumentDataType_match_specifier != 1) /* If its not match */
                {
                    /* Print a message and break the loop */
                    printf("Error data type mismatch\n");
                    break;
                }
                else /* If its match */
                {
                    /* Formate and convert the corresponding argiment */
                    formated_argiment = argimentFormattingAnd_converting(corresponding_argiment);
                    
                    /* Append to the charchter to the buffer */
                    append_inputString_to_theBuffer(formated_argiment);

                    /* Write the content of the buffer to the main output and break the loop */
                    write_theBuffer_toStdOutput();

                    /* Incrise the charchter index after the specifier to get the next charchter */
                    input_string_index++;
                }
                
                
            }
            
        }
        
    }
    
    /* Free all the pionter */
    va_end(input_string_arg);
    free(input_string_buffer);
    free(corresponding_argiment);
    free(formated_argiment);

    /* Print a message if string is empty */
    printf("Error zero-length gnu_printf format string\n");
}
