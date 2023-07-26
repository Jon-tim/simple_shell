#include "shell.h"
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: argument vector
 * Return: Always 0 (Success).
 */
int main(int argc, char **argv)
{

	if (argc == 2)
	{
		execute_from_file(argv[1], argv[0]);
	}
	else if (argc > 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		execute_interactive(argc);
	}

	return (0);
}

/**
 * execute_from_file - Executes commands from a file
 * @filename: Name of the file
 * @program_name: Name of the program.
 */
void execute_from_file(const char *filename, const char *program_name)
{
	char command[BUFFER_SIZE];
	int file_fd = open(filename, O_RDONLY);
	ssize_t bytes_read;

	if (file_fd == -1)
	{
		fprintf(stderr, "%s: 0: Can't open %s\n", program_name, filename);
		exit(127);
	}

	while ((bytes_read = read(file_fd, command, sizeof(command))) > 0)
	{
		execute_command(command);
	}
	close(file_fd);
}

/**
 * execute_interactive - Executes commands from the terminal
 * @argc: Number of arguments.
 */
void execute_interactive(int argc)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;

	const char prompt[] = "($) ";

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
			fflush(stdout);
		}
		characters_read = getline(&command, &bufsize, stdin);
		if (characters_read == -1)
		{
			break;
		}
		handle_external(argc, command);
		free(command);
	}

	free(command);
}
