#ifndef _MY_SHELL_
#define _MY_SHELL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
void print_error(const char *error_message);
void execute_command(char *command);
char *read_command();
#endif

