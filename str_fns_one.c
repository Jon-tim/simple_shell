#include "shell.h"

/**
 * _strncmp - compares two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 * Return: -1 if s1 != s2 and 0 if s1 = s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (-1);
		}
	}
	return (0);
}

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to copy
 * Return: pointer to dest
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: duplicate of string.
 */
char *_strdup(char *str)
{
	char *str_alt;
	int i, j = 0;

	while (str[j] != '\0')
	{
		/* code */
		j++;
	}

	str_alt = malloc(sizeof(char) * (j + 1));
	if (str_alt == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		/* code */
		str_alt[i] = str[i];
	}
	str_alt[i] = '\0';
	return (str_alt);
}

