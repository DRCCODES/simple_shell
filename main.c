#include <unistd.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <sys/wait.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

int is_it_there(const char * path) {
  struct stat path_stat;
  stat(path, & path_stat);
  return S_ISREG(path_stat.st_mode);
}

int main(int argc, char ** args, char ** envp) {
  while (1) {
    char input[1024];
    char * ptr = input;
    char * args[1024] = {
      NULL
    };
    char * path = getenv("PATH");
    char * x = strtok(path, ":");
    int j = 0;
    int z;
    char * box[1024];
    char * chest;
    size_t n = sizeof(path) / sizeof(path[0]);
    size_t size = 0;
    int check = 0;
    char * tmp;
    int wstatus;

    while (x != NULL) {
      box[j++] = x;
      x = strtok(NULL, ":");
    }

    printf("$ ");
    getline( & ptr, & size, stdin);

    if ( * ptr == '\n') continue;

    for (int i = 0; i < sizeof(args) && * ptr; ptr++) {
      if ( * ptr == ' ') continue;
      if ( * ptr == '\n') break;
      for (args[i++] = ptr;* ptr && * ptr != ' ' && * ptr != '\n'; ptr++);
      * ptr = '\0';
    }

    if (strcmp("exit", args[0]) == 0) return 0;

    for (z = 0; z < n - 1; z++) {
      //strcat(str1, str2);
      chest = strdup(box[z]);
      if (z == 0) {

        tmp = strcat(chest, args[0]);
      } else {
        tmp = strcat(chest, "/");
        tmp = strcat(tmp, args[0]);

      }

      //printf("%s\n",tmp);
      check = is_it_there(tmp);
      if (check == 1) {
        args[0] = tmp;
        break;
      }
      z++;
    }

    signal(SIGINT, SIG_DFL);

    if (fork() == 0) {
      if (execve(args[0], args, NULL) == -1) {
        perror("Error:");
      } else {
        exit(execve(args[0], args, NULL));
      }
    }
    signal(SIGINT, SIG_IGN);

    wait( & wstatus);

  }
}
