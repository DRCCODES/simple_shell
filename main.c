#include "shell.h"

void sigintHandler() 
{ 
    signal(SIGINT, sigintHandler); 
    printf("\n$ "); 
    fflush(stdout); 
} 

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
	write (1, p, strlen (p));
	return(0);
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
void copy_envp(char **envp,char **my_envp)
{
	int i;
	for(i = 0; envp[i] != NULL; i++) {
		my_envp[i] = (char *)malloc(sizeof(char) * (strlen(envp[i]) + 1));
		memcpy(my_envp[i], envp[i], strlen(envp[i]));
	}
}

char *path_check(char *args,char *array[],char *path)
{
int check;
size_t z = 0;
char *tmp;
if (strncmp(args, "/", 1) != 0)
            while(z < sizeof(path) - 1)
            {
                tmp = strdup(array[z]);
                if(z == 0)
                {
                 tmp = strcat(tmp , args);
                }
                else
                {
                tmp = strcat(tmp,"/");
                tmp = strcat(tmp , args);
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

int *split_path(char *x, char *array[])
{

    int i = 0;

	x += 5;

    x = strtok(x,":");
        while (x != '\0')
    {
        array[i++] = x;
        x = strtok (NULL, ":");
    }
return (0);
}

int *split_to_args(char *ptr,char **args)
{        
    size_t i;
    
    for (i = 0; i < sizeof(args) && *ptr; ptr++) 
        {
            if (*ptr == ' ') continue;
            if (*ptr == '\n') break;
            for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++);
            *ptr = '\0';
        }
return (0);
}

int main(int argc, char **args, char **envp)
{
char *path = (char *)malloc(sizeof(char) * 256);
char **my_envp = malloc(sizeof(envp) * size_of_envp(envp) + 1), c;

if (strcmp("exit", args[0]) == 0) 
return(0);
copy_envp(envp,my_envp);
get_path(my_envp, path);
signal(SIGINT, sigintHandler);
for(;;) 
{
char *array[sizeof(path) + 1];
char *x = (char *)malloc(sizeof(char) * 256);
char *ptr = (char *)malloc(sizeof(char) * 1024);
size_t size = 1024;
char *args[1024] = {NULL};
int wstatus , check;

x = strdup(path);
split_path(x,array);
_fputs("$ ");
c = getline(&ptr, &size, stdin);
if (c == EOF) return (0);
if (*ptr == '\n' || argc == 0) continue;
split_to_args(ptr,args);
if (strcmp("exit", args[0]) == 0 ) return (0);
args[0] = path_check(args[0], array, path);
check = is_it_there(path_check(args[0], array, path));
if (fork() == 0)
exit(execve(args[0], args, my_envp));
if (check != 1)
{
_fputs(args[0]);
_fputs(": command not found\n");
}
free_args(args);
wait(&wstatus);
}
}
