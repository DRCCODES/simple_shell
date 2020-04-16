#include "shell.h"

int _fputs(char *p)
{
	write (1, p, _strlen (p));
	return(0);
}

void sigintHandler(int sig_num) 
{ 
    signal(SIGINT, sigintHandler); 
    printf("\n$ "); 
    fflush(stdout); 
} 


void copy_envp(char **envp,char **my_envp)
{
	int i;
	for(i = 0; envp[i] != NULL; i++) {
		my_envp[i] = (char *)malloc(sizeof(char) * (_strlen(envp[i]) + 1));
		_memcpy(my_envp[i], envp[i], _strlen(envp[i]));
	}
}

int main( int argc, char **args, char **envp)
{
    signal(SIGINT, sigintHandler); 
    char *path = (char *)malloc(sizeof(char) * 256);
    char **my_envp = malloc(sizeof(envp) * size_of_envp(envp) + 1);
    int i = 0;
    
    copy_envp(envp,my_envp);
    get_path(my_envp, path);

    char *array[sizeof(path) + 1];
    char *x = path;
    x += 5;
    x = strtok(x,":");
        while (x != NULL)
    {
        array[i++] = x;
        x = strtok (NULL, ":");
    }
    char c;
    
    for(;;) {
        char *ptr = (char *)malloc(sizeof(char) * 256);
        size_t size = 32;
        char *args[1024] = {NULL};
        int wstatus;
        int check;
        char *tmp;
        int z = 0;
        _fputs("$ ");
        c = getline(&ptr, &size, stdin);
        if (c == EOF) return (0);
        if (*ptr == '\n') continue;
        for (i = 0; i < sizeof(args) && *ptr; ptr++) {
            if (*ptr == ' ') continue;
            if (*ptr == '\n') break;
            for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++);
            *ptr = '\0';
        }
        if (_strcmp(args[0], "/") != 0)
            while(z < sizeof(path) - 1)
            {
                tmp = strdup(array[z]);
                if(z == 0)
                {
                 tmp = _strcat(tmp , args[0]);
                }
                else
                {
                tmp = strcat(tmp,"/");
                tmp = strcat(tmp , args[0]);
                }
                check = is_it_there(tmp);
                if (check == 1)
                {
                args[0] = tmp;
                break;
                }
                z++;
            }
        if (_strcmp("exit", args[0]) == 0) return 0;
   if (fork() == 0)
        {
        exit(execve(args[0], args, my_envp));
        }
    if (check != 1)
    {
        _fputs(args[0]);
        _fputs(": command not found\n");
    }
        free_args(args);
        wait(&wstatus);
    }
}
