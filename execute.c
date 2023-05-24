#include "shell.h"

/**
 * get_command_path - Gets the command path
 * @command: The command to get the path for
 * Return: The command path
 */
char *get_command_path(char *command)
{
	if (command[0] == '\\' || command[0] == '/')
	{
		if (access(command, X_OK) == 0)
		{
			return (strdup(command));
		}
	}
	else
	{
		char *path = getenv("PATH");
		char *path_copy = strdup(path);
		char *token = strtok(path_copy, ":");

		while (token != NULL)
		{
			char *command_path = malloc(strlen(token) + strlen(command) + 2);

			sprintf(command_path, "%s/%s", token, command);

			if (access(command_path, X_OK) == 0)
			{
				free(path_copy);
				return (command_path);
			}

			free(command_path);
			token = strtok(NULL, ":");
		}

		free(path_copy);
	}
	return (NULL);
}

/**
 * is_builtin - Checks if the command is a builtin
 * @command: The command to check
 * Return: 1 if the command is builtin, 0 otherwise
 */
int is_builtin(const char *command)
{
	int i;

	const char *builtins[] = {"exit", "env", "setenv", "unsetenv", "cd"};
	int num_builtins = sizeof(builtins) / sizeof(builtins[0]);

	for (i = 0; i < num_builtins; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * execute_semicolon_command - Executes commands separated by a semicolon
 * @command: The command to execute
 */
void execute_semicolon_command(char *command)
{
	char *command_token;
	char *saveptr;

	command_token = strtok_r(command, ";", &saveptr);

	while (command_token != NULL)
	{

		char *trimmed_command = trim_whitespace(command_token);

		execute_command(trimmed_command);

		command_token = strtok_r(NULL, ";", &saveptr);
	}
}

/**
 * execute_command - Executes a command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	char *token, *command_path;
	pid_t pid;
	int arg_count = 0, status;
	char *args[MAX_INPUT_LENGTH];

	rep_var(command);
	if (command == NULL || command[0] == '\0' || command[0] == '#')
		return;
	token = strtok(command, " ");
	while (token != NULL && arg_count < MAX_INPUT_LENGTH - 1)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
	if (is_builtin(args[0]))
	{
		execute_builtin(args[0], args);
		return;
	}
	command_path = get_command_path(args[0]);
	if (command_path == NULL)
	{
		printf("Command not found: %s\n", args[0]);
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command_path, args, NULL);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	free(command_path);
}

/**
 * handle_next_command - Handles the next command
 * @command: The command to handle
 */
void handle_next_command(char *command)
{
	bool success = true;
	char *next_operator, *operator, *next_command;

	next_operator = _strpbrk(command, "&|");

	if (next_operator != NULL)
	{
		next_operator = trim_whitespace(next_operator);
		operator = next_operator;

		next_command = next_operator + 1;
		next_command = trim_whitespace(next_command);

		if (*operator == '&' && success)
		{
			execute_command(next_command);
		}
		else if (*operator == '|' && !success)
		{
			execute_command(next_command);
		}
	}
}

