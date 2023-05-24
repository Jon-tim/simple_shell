#include "shell.h"

/**
 * _unsetenv - removes/deletes an environment variable from the environment
 * @name: name of the environment variable to remove
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char *name)
{

	int name_len = _strlen(name), i = 0;

	while (environ[i] != NULL)
	{
		/* code */
		if (_strncmp(name, environ[i], name_len) == 0)
		{
			free(environ[i]);
			environ[i] = NULL;
		}
		i++;
	}
	return (0);
}

/**
 * _setenv - sets an environment variable without using setenv
 * @name: name of environment variable
 * @value: value of environment variable
 * @overwrite: whether to overwrite the variable or not
 * Return: 0 on success, -1 on failure
 */

int _setenv(char *name, char *value, int overwrite)
{
	int name_len = _strlen(name), value_len = _strlen(value), i = 0, env_len = 0;
	char *concatenated;

	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], name_len) == 0)
		{
			if (overwrite == 1)
			{
				concatenated = concat_name_value(name, value);
				if (concatenated != NULL)
				{
					_strncpy(environ[i], concatenated, name_len + value_len + 2);
					free(concatenated);
				}
			}
			return (0);
		}
		i++;
	}
	while (environ[env_len] != NULL)
		env_len++;
	concatenated = concat_name_value(name, value);
	if (concatenated != NULL)
	{
		environ[env_len] = malloc(sizeof(char) * (_strlen(concatenated) + 1));
		if (environ[env_len] == NULL)
		{
			free(concatenated);
			return (-1);
		}
		_strcpy(environ[env_len], concatenated);
		environ[env_len + 1] = NULL;
		free(concatenated);
	}
	return (0);
}

