#include "shell.h"
/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *command;

	while (1)
	{
<<<<<<< HEAD
		if (isatty(STDIN_FILENO))
=======
		FILE *file = fopen(argv[1], "r");

		if (file == NULL)
		{
			printf("%s:0: Can't open %s\n", argv[0], argv[1]);
			return (EXIT_FAILURE);
		}
		while (fgets(line, sizeof(line), file))
>>>>>>> d986e09391764cbfe6072a940404325bb86ea5ba
		{
			write(STDOUT_FILENO, "simple_shell$ ", 14);
			fflush(stdout);
		}
<<<<<<< HEAD
		command = read_command();

		if (command != NULL && *command != '\0')
			execute_command(command);

		free(command);
=======
		fclose(file);
	}
	else
	{
		if (isatty(STDIN_FILENO))
		{
			while (1)
			{
				write(STDOUT_FILENO, "$ ", 2);
				fflush(stdout);
				bytes_read = getline(&input, &input_length, stdin);
				if (bytes_read == -1)
					break;
				input[strcspn(input, "\n")] = '\0';
				if (_strlen(input) == 0)
					continue;
				execute_semicolon_command(input);
			}
		}
		else
		{
			while (fgrts(line, sizeof(line), stdin))
			{
				line[strcspn(line, "\n")] = '\0';
				execute_command(line);
			}
		}
		free(input);
		return (0);
>>>>>>> d986e09391764cbfe6072a940404325bb86ea5ba
	}
	return (0);
}

