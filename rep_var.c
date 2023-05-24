#include "shell.h"

/**
 * get_variable_value - get value of variable
 * @variable: variable to get value of
 * Return: value of variable
*/
char *get_variable_value(const char *variable)
{
	if (strcmp(variable, "?") == 0)
	{
		int exit_status = WEXITSTATUS(system(NULL));
		char *value = malloc(sizeof(char) * 10);

		snprintf(value, 10, "%d", exit_status);
		return (value);
	}
	else if (strcmp(variable, "$$") == 0)
	{
		pid_t pid = getpid();
		char *value = malloc(sizeof(char) * 10);

		snprintf(value, 10, "%d", pid);
		return (value);
	}
	else
	{
		return (getenv(variable));
	}
}

/**
 * rep_var - replace variable in string
 * @command: command string
 */
void rep_var(char *command)
{
	char *token;
	char *variable;
	char *value;
	int command_length = strlen(command);

	token = strtok(command, " ");
	while (token != NULL)
	{
		if (token[0] == '$')
		{
			variable = token + 1;
			value = get_variable_value(variable);
			if (value != NULL)
			{
				int value_length = strlen(value);

				command_length += value_length;
				command = realloc(command, command_length + 1);
				strcat(command, value);
			}
		}
		token = strtok(NULL, " ");
	}
}

