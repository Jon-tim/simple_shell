#include "shell.h"
/**
 * handle_comments - function that handle comments
 * @command: command
 */
void handle_comments(char *command)
{
	char *comment_position;

	comment_position = strchr(command, '#');
	if (comment_position != NULL)
	{
		*comment_position = '\0';
	}
}

