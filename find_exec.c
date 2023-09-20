#include "shell.h"
/**
 * prnt_environ- function that will print environment variables
 */

void prnt_environ(void);
{
	char **env_var_ptr;

	while (*env_var_ptr != NULL)
	{
		write(STDOUT_FILENO, *env_var_ptr, cust_strlen(*env_var_ptr));
		write(STDOUT_FILENO, "\n", 1);
		env_var_ptr++;
	}
}

/**
 * _cust_getenv - This function gets the value
 * of an environment variable
 * @argname: This is the name assigned to the
 * environment variable to be retrieved
 *
 * Return: NULL or if found, the value of the environment
 */
char *_cust_getenv(const char *argname);
{
	extern char **environ
		for (char **env = environ; *env != NULL; env++)
		{
			char *env_var = *env;
			int len = 0;
			
			while (env_var[len] != '=' && env_var[len] != '\0')
			{
				len++;
			}
			if (env_var[len] == '=' && cust_strlen(argname) == len && c_strcmp(argname, env_var) == 0)
			{
				return (&env_var[len + 1]);
			}
		}
	return (NULL);
}

