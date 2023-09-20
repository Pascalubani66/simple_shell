#include "shell.h"
/**
 * prnt_environ- function that will print environment variables
 */

void prnt_environ(void)
{
	char **env_ptr;

	while (*env_ptr != NULL)
	{
		write(STDOUT_FILENO, *env_ptr, cust_strlen(*env_ptr));
		write(STDOUT_FILENO, "\n", 1);
		env_ptr++;
	}
}
