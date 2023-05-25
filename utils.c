#include "shell.h"
/**
 * read_command - Reads a command from stdin
 * Return: The command
 */
char *read_command()
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t len = getline(&command, &bufsize, stdin);

	if (len == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_error("getline error");
		}
	}

	command[strcspn(command, "\n")] = '\0';

	return (command);
}

