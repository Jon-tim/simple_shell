#include "shell.h"
/**
 * alias_command - handles the alias command
 * @list: alias list
 * @argc: number of arguments
 * @argv: array of arguments
 */
void alias_command(AliasList *list, int argc, char **argv)
{
	if (argc == 1)
	{
		print_aliases(list);
	}
	else
	{
		int i;

		for (i = 1; i < argc; i++)
		{
			char *name = argv[i];
			char *value = strchr(name, '=');

			if (value != NULL)
			{
				*value = '\0';
				value++;
				add_alias(list, name, value);
			}
			else
			{
				Alias *alias = find_alias(list, name);

				if (alias != NULL)
				{
					print_alias(alias);
				}
			}
		}
	}
}

