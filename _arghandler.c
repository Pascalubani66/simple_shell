#include "shell.h"

int take_cmd(char *prmpt)
{
	ssize_t size_ofchar_read = read(STDIN_FILENO, prmpt, MAX_DISPLAY_LENGTH);
	if (size_ofchar_read < 0)
	{
	perror("Input error");
	exit(1);
	}
    else if (size_ofchar_read == 0)
    {
        // Handle end of file (Ctrl+D)
        write(STDOUT_FILENO, "\n", 1);
        exit(0);
    }
    prmpt[size_ofchar_read] = '\0';
    return size_ofchar_read;
}

void exec_prmpt(char *command_line)
{
    char *cmd[MAXIMUM_COMMAND];
    int cmdval = 0;
    char *tokn = strtok(command_line, " ");

    while (tokn != NULL && cmdval < MAXIMUM_COMMAND - 1)
    {
        cmd[cmdval++] = tokn;
        tokn = strtok(NULL, " ");
    }

    cmd[cmdval] = NULL;

    if (cmdval > 0 && c_strcmp(cmd[0], "exit") == 0)
    {
        exit(0);
    }

    char *path = _custgetenv("PATH");
    if (path != NULL)
    {
	    char *tokn - strtok(path, ":");
	    while (tokn != NULL)
	    {
		    char entirepath[MAXIMUM_COMMAND];
		    char *ptr = entirepath;
		    while (*tokn != '\0')
		    {
			    *ptr++ = *tokn++;
		    }
		    *ptr++ = '/';
		    char *cmdptr = cmd[0];
		    while (*cmdptr != '\0')
		    {
			    *ptr++ = *cmdptr++;
		    }
		    *ptr = '\0';
		    if (access(entirepath, X_OK) == 0)
		    {
			    pid_t child_processid = fork();
			    if (child_processid < 0)
			    {
				    perror("Fork Failed");
				    exit(1);
			    }
			    else if (child_processid == 0)
			    {
				    if (execve(entirepath, cmd, NULL) >= 0)
				    {
					    exit(0);
				    }
				    else
				    {
					    char error_message[] = "Command not found: ";
					    write(STDERR_FILENO, error_message, strlen(error_message));
        exit(1);
    }
			    }
			    else
			    {
				    int report;
				    waitpid(child_processid, &report, 0);
				    return;
			    }
		    }
		    
		    tokn = strtok(NULL, ":");
	    }
    }
    char error_message[] = "command not found: ";
    write(STDERR_FILENO, error_message, cust_strlen(error_message));
    write(STDERR_FILENO, cmd[0], cust_strlen(cmd[0]));
    write(STDERR_FILENO, "\n", 1);
}
