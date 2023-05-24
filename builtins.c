#include "shell.h"

/**
 * builtin_exit - exits the shell
 * @status_code: the exit status code
 */
void builtin_exit(char *status_code)
{
	int status = EXIT_SUCCESS;

	if (status_code != NULL)
	{
		status = atoi(status_code);
	}

	exit(status);
}
/**
 * builtin_env - prints the environment
 */
void builtin_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * execute_builtin - executes a builtin command
 * @command: the command to execute
 * @args: the arguments to the command
 */
void execute_builtin(char *command, char *args[])
{
	if (_strcmp(command, "exit") == 0)
	{
		builtin_exit(args[1]);
	}
	else if (_strcmp(command, "env") == 0)
	{
		builtin_env();
	}
	else if (_strcmp(command, "setenv") == 0)
	{
		if (args[1] != NULL && args[2] != NULL)
		{
			int overwrite = 1;

			_setenv(args[1], args[2], overwrite);
		}
		else
		{
			fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		}
	}
	else if (_strcmp(command, "unsetenv") == 0)
	{
		if (args[1] != NULL)
		{
			_unsetenv(args[1]);
		}
		else
		{
			fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		}
	}
	else if (_strcmp(command, "cd") == 0)
	{
		builtin_cd(args[1]);
	}
}

