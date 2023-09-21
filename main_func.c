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
char *buff = NULL;
char **arv;
size_t size = 0;
int main(void)
{
	ssize_t len = 0;
	char **arv;
	list_path *head = NULL;
	void (*f)(char **);
	char *pathname;
	int status;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		int pid = fork();
		_puts("#cisfun$ ");
	size_t len = my_get_line(&buff, &size, stdin);
		_EOF(len, buff);

		if (len == -1)
		{
			perror("my_get_line");
			break;
		}
		if (len > 0)
		{	
			arv = splitstring(buff, " \n");
			if (!arv || !arv[0])
			{
				free(arv);
				continue;
			}
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

				if (pid == 0)
				{
					execute(arv);
					exit(EXIT_SUCCESS);
				}
				else if (pid < 0)
				{
					perror("fork");
				}
				else
				{
					do
					{
						waitpid(pid, &status, WUNTRACED);
					}
					while (!WIFEXITED(status) && !WIFSIGNALED(status));
				}
			}
			
			free(arv);
			{
			{
				free_list(head);
				free(buff);
				buff = NULL;
				size = 0;
			}
			return (0);
			}
