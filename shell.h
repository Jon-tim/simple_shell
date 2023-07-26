#ifndef SHELL
#define SHELL

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIMITER " \t\r\n\a"
#define MAX_ARGUMENTS 64
#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 4096
#define MAX_ALIAS_LENGTH 100
#define MAX_VALUE_LENGTH 100

extern char **environ;

void print_alias(Alias *alias);
void print_aliases(AliasList *list);
void add_alias(AliasList *list, char *name, char *value);
char *search_path(char *command);
void parse_arguments(char *command, char *arguments[]);
void handle_builtin(char *arguments[]);
void handle_external(int argc, char *command);
void execute_command(char *command);
void handle_exit(char *arguments[]);
void handle_setenv(char *arguments[]);
void handle_unsetenv(char *arguments[]);
void handle_cd(char *arguments[]);
void handle_env(void);
void execute_from_file(const char *filename, const char *program_name);
void execute_interactive(int argc);
void handle_comments(char *command);
#endif

