#include "shell.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *input = NULL;
	size_t input_length = 0;
	ssize_t bytes_read;
	char line[MAX_INPUT_LENGTH];

	if (argc == 2)
	{
		FILE *file = fopen(argv[1], "r");

		if (file == NULL)
		{
			perror("Error opening file");
			return (EXIT_FAILURE);
		}
		while (fgets(line, sizeof(line), file))
		{
			line[strcspn(line, "\n")] = '\0';
			execute_command(line);
		}
		fclose(file);
	}
	else
	{
		while (1)
		{
			printf("#cisfun$  ");
			bytes_read = getline(&input, &input_length, stdin);
			if (bytes_read == -1)
				break;
			input[strcspn(input, "\n")] = '\0';
			if (_strlen(input) == 0)
				continue;
			execute_semicolon_command(input);
		}
		free(input);
		return (0);
	}
	return (0);
}

