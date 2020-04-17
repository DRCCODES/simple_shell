#include "shell.h"

/**
* sigintHandler - ignores ctrl c to prevent acc closure
* 
* @sig_unm: Dummy argument
*
* Return: N/A
*
*/
void sigintHandler(int sig_num)
{
	int i = sig_num;
	i = 0;
	i++;
	i--;

	signal(SIGINT, sigintHandler);
	printf("\n$ ");
	fflush(stdout);
}


int main(int argc, char **args, char **envp)
{
char *path = (char *)malloc(sizeof(char) * 256);
char **my_envp = malloc(sizeof(envp) * size_of_envp(envp) + 1), c;

if (strcmp("exit", args[0]) == 0)
exit(98);
copy_envp(envp, my_envp);
get_path(my_envp, path);

signal(SIGINT, sigintHandler);

for (;;)
{
char *array[sizeof(path) + 1];
char *x = (char *)malloc(sizeof(char) * 256);
char *ptr = (char *)malloc(sizeof(char) * 1024);
size_t size = 1024;
char *args[1024] = {NULL};
int wstatus, check;

x = strdup(path);
split_path(x, array);
_fputs("$ ");
c = getline(&ptr, &size, stdin);
if (c == EOF)
	exit(98);
if (*ptr == '\n' || argc == 0)
	continue;
split_to_args(ptr, args);
if (strcmp("exit", args[0]) == 0)
	exit(98);
args[0] = path_check(args[0], array, path);
if (fork() == 0)
exit(execve(args[0], args, my_envp));
check = is_it_there(args[0]);
if (check != 1)
{
_fputs(args[0]);
_fputs(": command not found\n");
}
free_args(args);
wait(&wstatus);
}
}

