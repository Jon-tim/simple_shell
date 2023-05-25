#include "shell.h"
/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *command;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "simple_shell$ ", 14);
			fflush(stdout);
		}
		command = read_command();

		if (command != NULL && *command != '\0')
		{
			if (is_exit_command(command))
				exit(EXIT_SUCCESS);
			execute_command(command);
		}

		free(command);
	}
	return (0);
}

