#include "shell.h"

/**
 * print_error - prints error message
 * @error_message: error message to print
 */
void print_error(const char *error_message)
{
	size_t len;

	len = strlen(error_message);
	write(STDERR_FILENO, error_message, len);
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

