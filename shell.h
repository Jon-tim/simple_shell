#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>

extern char **environ;

#define MAX_INPUT_LENGTH 256
#define BUFFER_SIZE 1024

void execute_command(char *command);
char *get_command_path(char *command);
char *custom_getline();
void execute_semicolon_command(char *command);
void handle_next_command(char *command);
char *get_variable_value(const char *variable);
void rep_var(char *command);

/*BUILTIN FUNCTIONS*/
int is_builtin(const char *command);
void builtin_exit(char *status_code);
void builtin_env(void);
void execute_builtin(char *command, char *args[]);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
void builtin_cd(char *directory);
int update_environment_variables(char *current_dir);
int change_directory(char *path);
char *get_directory_path(char *directory);

/*STRING FUNCTIONS*/
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strlen(const char *str);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *concat_name_value(const char *name, const char *value);
char *trim_whitespace(char *str);
char *_strpbrk(const char *str, const char *charset);

#endif

