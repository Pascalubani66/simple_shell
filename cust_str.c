#include "shell.h"

/**
*size_t - the return type of the function
*cust_strlen: the identifier used to call function
*inpstr: pointer to a constant character
Return: length
*/

size_t cust_strlen(const char *inpstr)
{
size_t length = 0;
while (inpstr[length] != '\0')
{
length++;
}
return length;
}

/**
*int - the return type of the function
*cust_strcmp: identifier to call function
**1st: parameter of function
**2st: parameter of funcion
*Return: an integer value
*/

int c_strcmp(const char *s1t, const char *s2t)//function to compare two strings//
while (*s1t != '\0' && *s2t != '\0') {
        if (*s1t != *s2t) {
            return (*s1t - *s2t);
        }
        s1t++;
        s2t++;
    }
    return (*s1t - *s2t);
}

char *c_str_chr(const char *string, int character)

{
if (str == NULL)
{
return NULL;
}
return strchr(str, character);
}

char *c_strdu_p(const char *string) 
{
    if (string == NULL) 
{
perror("Value is NULL");
exit(1); // Handle memory allocation error gracefully
}
char *val = strdup(str); // Allocate memory and copy the value
if (val == NULL)
{
perror("Memory allocation failed");
exit(1); // Handle memory allocation error gracefully
}
return val;
