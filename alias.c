#include "shell.h"

/**
 * create_alias_list - creates a linked list of aliases
 * Return: pointer to the head of the list
 */
AliasList *create_alias_list()
{
	AliasList *list = malloc(sizeof(AliasList));

	list->head = NULL;
	return (list);
}

/**
 * print_alias - prints an alias
 * @alias: alias to print
 */
void print_alias(Alias *alias)
{
	printf("%s='%s'\n", alias->name, alias->value);
}

/**
 * print_aliases - prints all aliases
 * @list: alias list
 */
void print_aliases(AliasList *list)
{
	Alias *current = list->head;

	while (current != NULL)
	{
		print_alias(current);
		current = current->next;
	}
}

/**
 * find_alias - finds an alias
 * @list: alias list
 * @name: name of the alias to find
 * Return: pointer to alias
 */
Alias *find_alias(AliasList *list, char *name)
{
	Alias *current = list->head;

	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

/**
 * add_alias - adds an alias
 * @list: alias list
 * @name: name of the alias
 * @value: value of the alias
 */
void add_alias(AliasList *list, char *name, char *value)
{
	Alias *alias = find_alias(list, name);

	if (alias != NULL)
	{
		strcpy(alias->value, value);
	}
	else
	{
		Alias *new_alias = malloc(sizeof(Alias));

		strcpy(new_alias->name, name);
		strcpy(new_alias->value, value);
		new_alias->next = list->head;
		list->head = new_alias;
	}
}

