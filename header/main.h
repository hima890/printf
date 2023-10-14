#ifndef MAIN_H
#define MAIN_H

/* Header files goes here */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


/* Defind morcos goes here*/
#define BUFFER_SIZE 1024

/* Defind struct goes here */


/*Functions prototypes goes here */
char *_printf(char *input_string, ...);
char *initializeStringBuffer(int buffer_size);
void *write_theBuffer_toStdOutput();
int *isValid_specifier(char input_string_specifier);
void *findTheCorresponding_argiment(char input_string_specifier, va_list input_string_arg);
int *isArgumentDataType_match_specifier(char input_string_specifier, void *corresponding_argiment);
void *argimentFormattingAnd_converting(void *corresponding_argiment);
void *convert(void *corresponding_argiment);

#endif
