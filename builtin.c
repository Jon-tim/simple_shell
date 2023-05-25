#include "shell.h"
/**
 * is_exit_command - checks if the command is exit
 * @command: command to check
 * Return: 1 if true, 0 if false
 */
int is_exit_command(char *command)
{
	if (strcmp(command, "exit") == 0)
		return (1);
	return (0);
}

