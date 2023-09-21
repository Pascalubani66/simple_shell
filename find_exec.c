#include "shell.h"


/**
 * _getenv - gets the value of the global variable
 * @name: name of the global variable
 * Return: string of value
 */
char *_getenv(const char *name)
{
	int i;

	if (!name)
		return NULL;

	for (i = 0; environ[i]; i++)
	{
		char *env_var = environ[i];
		int j;
		
		for (j = 0; name[j] != '\0'; j++)
		{
			if (name[j] != env_var[j])
				break;
		}
		if (name[j] == '\0' && env_var[j] == '=')
		{
			return &env_var[j + 1];
		}
	}
	
	return NULL;
}


/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

list_path *add_node_end(list_path **head, char *str)
{

	list_path *tmp;
	list_path *new;

	new = malloc(sizeof(list_path));

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;

	new->p = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}

	return (*head);
}


/**
 * linkpath - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
list_path *linkpath(char *path)
{
	list_path *head = '\0';
	char *token;
	char *cpath = _strdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * _which - finds the pathname of a filename
 * @filename: name of file or command
 * @head: head of linked list of path directories
 * Return: pathname of filename or NULL if no match
 */
char *_which(char *filename, list_path *head)
{
	char *string;
	list_path *tmp = head;
	char *path = _getenv("PATH");

	while (tmp)
	{
		char *token = strtok(path, ":");
		while (token)
		{
			string = concat_all(token, "/", filename);

			if (access(string, X_OK) == 0)
			{
				return string;
			}
			free(string);
			token = strtok(NULL, ":");
		}
		
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * free_list - frees a list_t
 *@head: pointer to our linked list
 */
void free_list(list_path *head)
{
	list_path *storage;

	while (head)
	{
		storage = head->p;
		free(head->dir);
		free(head);
		head = storage;
	}

}
