#include "shell.h"

/**
 * size_of_envp - finds size of envp
 *
 * @envp: target to get size of
 * Return: int j;
 */
int size_of_envp(char **envp)
{
	int j = 0;

	while (*envp)
{
	envp++;
	j++;
}
return (j);
}
/**
 * is_it_there - checks if path is valid
 *
 * @path: str parth to cmd or file
 *
 * Return: 0 or 1
 *
 */
int is_it_there(const char *path)
{
	struct stat path_stat;

	stat(path, &path_stat);

	return (S_ISREG(path_stat.st_mode));
}
/**
 * bezeros - fills s with /0
 *
 * @s: the str to fill
 *
 * @n: size/len of s
 *
 * Return: N/A
 *
 */
void bezeros(void *s, size_t n)
{
	char *c = s;

	size_t i = 0;

	for (i = 0; i < n; ++i)
	c[i] = '\0';
}
/**
 * free_args - frees the arguments
 *
 * @my_args: arguments to be freed
 *
 * Return: N/A
 *
 */
void free_args(char **my_args)
{
	int i;

	for (i = 0; my_args[i] != NULL; i++)
	{
		bezeros(my_args[i], _strlen(my_args[i]) + 1);
		my_args[i] = NULL;
		free(my_args[i]);
	}
}
/**
 * get_path - gets PATH
 *
 * @tmp_envp: Holds envp
 *
 * @path: path to bin
 *
 * Return: N/A
 *
 */
void get_path(char **tmp_envp, char *path)
{
	int count = 0;

	char *tmp;

	while (1)
		{
		tmp = _strstr(tmp_envp[count], "PATH");
		if (tmp == NULL)
		{
			count++;
		}
		else
		{
			break;
		}
	}
_strncpy(path, tmp, _strlen(tmp));
}
