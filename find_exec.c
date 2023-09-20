#include "shell.h"

char *_custgetenv(char *argname) 
{
    if (argname == NULL)
    {
        perror("Name is NULL");
        return NULL;
    }

    size_t argname_length = strlen(argname);

    for (int m = 0; environ[m]; m++) 
{
	if (c_strcmp(argname, environ[m]) == 0) 
	{
		char *posit = c_str_chr(environ[m], '='); // Find the position of '='
		if (posit)
		{
			posit++;i
				char *val = c_strdu_p(posit);  // Move past '='
			return val;// Allocate memory and copy the value
		}
		else
		{
			return NULL; // '=' not found, invalid environment variable
		}
	}
}

return NULL; // Variable not found
}
void prnt_environ()
{
	char **env_ptr = environ;
	while (*env_ptr != NULL)
	{
		write(STDOUT_FILENO, *env_ptr, cust_strlen(*env_ptr));
		write(STDOUT_FILENO, "\n", 1);
		env_ptr++;
	}
}
