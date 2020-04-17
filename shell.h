#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *_memcpy(char *dest, char *src, unsigned int n);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int size_of_envp(char **envp);
int is_it_there(const char *path);
void bezeros(void *s, size_t n);
void free_args(char **my_args);
void get_path(char **tmp_envp, char *path);
int _fputs(char *p);
void copy_envp(char **envp, char **my_envp);
char *path_check(char *args, char *array[], char *path);
int *split_path(char *x, char *array[]);
int *split_to_args(char *ptr,char **args);

#endif
