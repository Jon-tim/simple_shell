#include "shell.h"
/**
 * parse_arguments - parses arguments
 * @command: command to parse
 * @arguments: arguments to parse.
 */
void parse_arguments(char *command, char *arguments[])
{
	char *token;
	int arg_count = 0;

	token = strtok(command, DELIMITER);
	while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
	{
		arguments[arg_count] = token;
		token = strtok(NULL, DELIMITER);
		arg_count++;
	}
	arguments[arg_count] = NULL;
}

/**
 * handle_builtin - handles builtins
 * @arguments: arguments to handle.
 */
void handle_builtin(char *arguments[])
{
	if (strcmp(arguments[0], "exit") == 0)
	{
		if (arguments[1] == NULL)
			exit(EXIT_SUCCESS);
		else if (arguments[2] == NULL)
			exit(atoi(arguments[1]));
		else
		{
			printf("Invalid number of arguments for exit\n");
			return;
		}
	}
	else if (strcmp(arguments[0], "env") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
		return;
	}
}

/**
 * execute_command - executes a command
 * @command: command to handle.
 */
void execute_command(char *command)
{
	int status;
	pid_t child_pid;
	char *arguments[MAX_ARGUMENTS],	*path_command;

	handle_comments(command);
	parse_arguments(command, arguments);
	if (access(arguments[0], X_OK) == 0)
		path_command = strdup(arguments[0]);
	else
		path_command = search_path(arguments[0]);
	if (path_command != NULL)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(path_command, arguments, NULL) == -1)
			{
				const char *error_message_1 = "%s: cannot access '";
				const char *error_message_2 = "': No such file or directory\n";

				fprintf(stderr, "%s%s%s", error_message_1, path_command, error_message_2);
				free(path_command);
				exit(2);
			}
			free(path_command);
		}
		else if (child_pid < 0)
			exit(1);
		else
		{
			do {
				waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	else
		fprintf(stderr, "%s: %s: command not found\n", __FILE__, arguments[0]);
	free(path_command);
}

/**
 * search_path - searches for a command in the PATH
 * @command: command to search for
 * Return: path of command if found, NULL if not.
 */
char *search_path(char *command)
{
	char *path = getenv("PATH");
	char *path_env = malloc(MAX_COMMAND_LENGTH);
	char *path_command = malloc(MAX_COMMAND_LENGTH);
	char *token;

	if (path == NULL)
	{
		free(path_env);
		free(path_command);
		return (NULL);
	}

	strcpy(path_env, path);
	token = strtok(path_env, ":");

	while (token != NULL)
	{
		strcpy(path_command, token);
		strcat(path_command, "/");
		strcat(path_command, command);

		if (access(path_command, X_OK) == 0)
		{
			free(path_env);
			return (path_command);
		}

		token = strtok(NULL, ":");
	}

	free(path_env);
	free(path_command);
	return (NULL);
}

/**
 * handle_external - handles external commands
 * @argc: number of arguments
 * @command: command to handle.
 */
void handle_external(int argc, char *command)
{
	char *builtin_commands[] = {"exit", "setenv", "unsetenv", "cd", "env"};
	int num_builtins = sizeof(builtin_commands) / sizeof(builtin_commands[0]), i;
	char *arguments[MAX_ARGUMENTS], command_copy[MAX_COMMAND_LENGTH];

	(void)argc;
	strcpy(command_copy, command);
	parse_arguments(command_copy, arguments);
	if (arguments[0] != NULL)
	{
		for (i = 0; i < num_builtins; i++)
		{
			if (strcmp(arguments[0], builtin_commands[i]) == 0)
			{
				if (strcmp(arguments[0], "exit") == 0)
					handle_exit(arguments);
				else if (strcmp(arguments[0], "setenv") == 0)
					handle_setenv(arguments);
				else if (strcmp(arguments[0], "unsetenv") == 0)
					handle_unsetenv(arguments);
				else if (strcmp(arguments[0], "cd") == 0)
					handle_cd(arguments);
				else if (strcmp(arguments[0], "env") == 0)
					handle_env();
				/*
				 * else if (strcmp(arguments[0], "alias") == 0)
					*alias_command(list, argc, arguments);
					*/
				return;
			}
		}
		execute_command(command);
	}
}

