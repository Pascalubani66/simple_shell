#include "shell.h"

/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
* _EOF - handles the End of File
* @len: return value of getline function
* @buff: buffer
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * _isatty - verif if terminal
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}
/**
 * main - Shell
 * Return: 0 on success
 */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, **arv;
	size_t size = 0;
	list_path *head = NULL;
	void (*f)(char **);
	char  *value, *pathname;

	signal(SIGINT, sig_handler);
	while (1)
	{
		_puts("#cisfun$ ");
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);

		if (len > 0)
		{
		arv = splitstring(buff, " \n");
		if (!arv || !arv[0])
		{
		free(arv);
		continue;
		}
			value = _getenv("PATH");
			head = linkpath(value);
			pathname = _which(arv[0], head);
			f = checkbuild(arv);
			if (f)
			{
				f(arv);
			}
			else if (!pathname)
			{
				perror(arv[0]);
			}
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				execute(arv);
			}
			
			free(arv);
		}
	}
	free_list(head);
	free(buff);

	return (0);
}
