#ifndef MAIN_H
#define MAIN_H

/* Header files goes here */
#include <stdbool.h>

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
char *appendToCharBuffer(char *buffer, const char *str_to_append);
char *initializeStringBuffer(int buffer_size);
bool containsStringSpecifier(const char input);
char *charToString(char character);
char *intToString(int number);
char *floatToString(float number);
void writeToConsole(const char *buffer);


#endif
