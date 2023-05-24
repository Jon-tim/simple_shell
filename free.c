#include "shell.h"
/**
 * free_arguments - free arguments
 * @args: arguments
 */
void free_arguments(char **args)
{
	int i;

	if (args == NULL)
		return;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}

