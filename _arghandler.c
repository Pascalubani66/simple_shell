#include "shell.h"


/**
 * splitstring - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */

char **splitstring(char *str, const char *delim)
{
	int i = 0;
	int j;
	char **array = malloc(sizeof(char *) * 2);
	char *token;

	if (!array)
	{
		perror(_getenv("_"));
		return (NULL);
	}

	token = strtok(str, delim);
	while (token)
	{
		array[i] = _strdup(token);
		if (!array[i])
		{
			perror(_getenv("-"));
			for (j = 0; j < i; j++)
			{
				free(array[j]);
			}
			free(array);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim);
		array = _realloc(array, sizeof(char *) * i, sizeof(char *) * (i + 2));
		array[i] = NULL;
	}
	return (array);
}

/**
 * execute - executes a command
 * @argv: array of arguments
 */

void execute(char **argv)
{

	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
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

/**
 * _realloc - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

/**
 * freearv - frees the array of pointers arv
 *@arv: array of pointers
 */

void freearv(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}
