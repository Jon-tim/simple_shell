#include "shell.h"
/**
 * handle_exit - handles the exit command
 * @arguments: arguments to exit
 */
void handle_exit(char *arguments[])
{
	if (arguments[1] != NULL)
	{
		int status;

		status = atoi(arguments[1]);
		if (status < 0)
		{
			const char *error_message_1 = "%s: %d: exit: Illegal number: %d\n";

			fprintf(stderr, error_message_1, arguments[0], getpid(), status);
			return;
		}
		exit(status);
	}
	else
	{
		exit(0);
	}
}

/**
 * handle_setenv - handles the setenv command
 * @arguments: arguments to setenv
 */
void handle_setenv(char *arguments[])
{
	if (arguments[1] != NULL && arguments[2] != NULL)
	{
		if (setenv(arguments[1], arguments[2], 1) != 0)
			printf("Error setting environment variable\n");
	}
	else
	{
		printf("Invalid number of arguments for setenv\n");
	}
}

/**
 * handle_unsetenv - handles the unsetenv command
 * @arguments: arguments to unsetenv
 */
void handle_unsetenv(char *arguments[])
{
	if (arguments[1] != NULL)
	{
		if (unsetenv(arguments[1]) != 0)
			printf("Error unsetting environment variable\n");
	}
	else
	{
		printf("Invalid number of arguments for unsetenv\n");
	}
}

/**
 * handle_env - handles the env command
 */
void handle_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * handle_cd - Changes the current directory
 * @arguments: arguments to cd
 */
void handle_cd(char *arguments[])
{
	char *dir = arguments[1];
	char current_dir[MAX_PATH_LENGTH];

	if (dir == NULL || strcmp(dir, "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return;
		}
		printf("%s\n", dir);
	}

	if (chdir(dir) == -1)
	{
		perror("cd");
		return;
	}

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}

	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", current_dir, 1);
}

