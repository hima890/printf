#ifndef MAIN_H
#define MAIN_H

/* Header files goes here */
#include <stdbool.h>

/* Defind morcos goes here*/
#define BUFFER_SIZE 1000024

/* Defind struct goes here */
/* Define a structure to associate specifiers with data types */
/**
 * struct list - dog data
 * @theSpicifier: name of the dog
 * @theDataType: age of the dog
 * Description: Defines metadata types
*/
struct list{
    char theSpicifier;
    char *theDataType;
};

/**
 * type_list - Type def. for dog stuct
*/
typedef struct list type_list;

/*Functions prototypes goes here */
int _printf(const char *format, ...);
char *appendToCharBuffer(char *buffer, const char *str_to_append);
char *initializeStringBuffer(int buffer_size);
bool isValidSpecifier(const char specifier);
char *charToString(char character);
char *intToString(int number);
char *negativeIntToString(int number);
char *floatToString(float number);
void writeToConsole(const char *buffer);


#endif
