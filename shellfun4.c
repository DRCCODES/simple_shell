#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * _fputs - writes out a str
 *
 * @p: the str
 *
 * Return: 0
 *
 */
int _fputs(char *p)
{
	write(1, p, strlen(p));
	return (0);
}
/**
 * copy_envp - copies envp
 *
 * @envp: environtal variables
 *
 * @my_envp: where to copy envp to
 *
 * Return: N/A
 *
 */
void copy_envp(char **envp, char **my_envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		my_envp[i] = (char *)malloc(sizeof(char) * (strlen(envp[i]) + 1));
		memcpy(my_envp[i], envp[i], strlen(envp[i]));
	}
}
/**
* path_check - checks if a path name or location exists
* @args: arguments passed through shell
* @array: passed ints
* @path: file path
*
* Return: tmp
*/
char *path_check(char *args, char *array[], char *path)
{
int check;
size_t z = 0;
char *tmp;

if (strncmp(args, "/", 1) != 0)
	while (z < sizeof(path) - 1)
	{
		tmp = strdup(array[z]);
		if (z == 0)
		{
			tmp = strcat(tmp, args);
		}
		else
		{
			tmp = strcat(tmp, "/");
			tmp = strcat(tmp, args);
		}
		check = is_it_there(tmp);
		if (check == 1)
		{
			break;
		}
		z++;
	}
	return (tmp);
}
/**
* split_path - splits a path into tokens
* @x: string
* @array: string
*
* Return: 0
*/
int *split_path(char *x, char *array[])
{
	int i = 0;

	x += 5;
	x = strtok(x, ":");
	while (x != '\0')
	{
		array[i++] = x;
		x = strtok(NULL, ":");
	}
	return (0);
}
/**
* split_to_args - splits a string into an array of arguments
* @ptr: string
* @args: args
*
* Return: 0
*/
int *split_to_args(char *ptr, char **args)
{
	size_t i;

	for (i = 0; i < sizeof(args) && *ptr; ptr++)
	{
		if (*ptr == ' ')
		{
			continue;
		}
		if (*ptr == '\n')
		{
			break;
		}
		for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++)
		;
		*ptr = '\0';
	}
return (0);
}
