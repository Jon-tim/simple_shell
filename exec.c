#include "shell.h"

/**
 * execute_command - executes a command
 * @command: command to execute
 */
void execute_command(char *command)
{
	int i, status;
	pid_t pid = fork();
	char *args[MAX_COMMAND_LENGTH], *program;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		program = strtok(command, " \t\n");
		args[0] = program;
		i = 1;
		while (args[i - 1] != NULL)
		{
			args[i] = strtok(NULL, " \t\n");
			i++;
		}
		execve(program, args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			print_error("waitpid error");
	}
}

