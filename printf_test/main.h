#ifndef MAIN_H
#define MAIN_H

/* Header files goes here */
#include <stdarg.h>



/* Defind morcos goes here*/
#define BUFFER_SIZE 1024

/* Defind struct goes here */
/* Define a structure to associate specifiers with data types */
typedef struct {
    char theSpicifier;
    char *theDataType;
} type_list;


/*Functions prototypes goes here */
int _printf(const char *format, ...);
char *appendToCharBuffer(char *buffer, char char_to_append);
char *initializeStringBuffer(int buffer_size);
int *isValid_specifier(char input_string_specifier);
void *argimentFormattingAnd_converting(void *corresponding_argiment);
void *convert(void *corresponding_argiment);
char *initializeStringBuffer(int buffer_size);
void writeToConsole(const char *buffer);


#endif
