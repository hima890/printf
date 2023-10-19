/* Header files goes here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * initializeStringBuffer - Initializes a character buffer of a specified size.
 *
 * @buffer_size: The size of the character buffer to allocate.
 *
 * Description:
 *   This function allocates a memory block for a character buffer of the given
 *   size and initializes it with all elements set to
 *  '\0'. It returns a pointer
 *   to the allocated memory.
 *
 *   If the provided buffer_size is less than or equal to 0, the function
 *   returns NULL and displays an error message.
 *
 *   The caller is responsible for freeing the allocated memory when it is no
 *   longer needed.
 *
 * Return: A pointer to the initialized character buffer, or NULL on failure.
 */

char *initializeStringBuffer(int buffer_size)
{
char *buffer_pionter; /* Pointer to the memory block */

if (buffer_size <= 0)
{
/* Handle invalid buffer size */
return (NULL);
}

/* Allocatedand signed the memory to the pointer */
buffer_pionter = (char *)malloc(sizeof(char) * buffer_size);
if (buffer_pionter == NULL)
{
/* Memory allocation failed */
return (NULL);
}

/* Set the memory block to 0 */
memset(buffer_pionter, 0, (sizeof(char) * buffer_size));
/* Return the memory pionter */
return (buffer_pionter);

/* Dont forget to free the pionter */
}
