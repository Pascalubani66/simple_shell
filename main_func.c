#include <shell.h>

int main()
{
    char prmpt[MAX_DISPLAY_LENGTH];
    while (1)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);
        if (take_cmd(prmpt) == 0)
        {
            continue;
        }

        prmpt[cust_strlen(prmpt) - 1] = '\0';

        if (c_strcmp(prmpt, "exit") == 0)
        {
            exit(0);
        }
	else if (c_strcmp(prmpt, "env") == 0)
	{
		prnt_environ();
	}
	else
	{
        char *_execpath = find_executable(prmpt);
        if (_execpath != NULL)
        {
            exec_prmpt(_execpath);
            free(_execpath);
        }
        else
	{
            char error_message[] = "Command not found: ";
            write(STDERR_FILENO, error_message, cust_strlen(error_message));
            write(STDERR_FILENO, prmpt, cust_strlen(prmpt));
            write(STDERR_FILENO, "\n", 1);
        }
	}
    }
    return 0;
}
