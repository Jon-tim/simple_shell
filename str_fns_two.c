#include "shell.h"
/**
 * _strcat - concatenates strings
 * @dest: destination
 * @src: source
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	char *p;

	p = dest;

	while (*p)
	{
		p++;
	}

	while (*src)
	{
		*p++ = *src++;
	}

	*p = '\0';
	return (dest);
}

/**
 * concat_name_value - concatenates a name and value adding `=` between them
 * @name: name of the environment variable
 * @value: value of the environment variable
 * Return: pointer to the concatenated string
 */
char *concat_name_value(const char *name, const char *value)
{
	int name_len = 0, value_len = 0, i, j;
	char *result;

	while (name[name_len] != '\0')
		name_len++;
	while (value[value_len] != '\0')
		value_len++;

	result = (char *)malloc(name_len + value_len + 2);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < name_len; i++)
	{
		result[i] = name[i];
	}
	result[name_len] = '=';
	for (j = 0; j < value_len; j++)
	{
		result[name_len + j + 1] = value[j];
	}
	result[name_len + value_len + 1] = '\0';
	return (result);
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 if equal, -1 if str1 < str2, 1 if str1 > str2
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * trim_whitespace - trims leading and trailing whitespace
 * @str: string to trim
 * Return: pointer to the trimmed string
 */
char *trim_whitespace(char *str)
{
	int start = 0, length;
	int end = strlen(str) - 1;

	while (isspace(str[start]))
	{
		start++;
	}
	while (end >= start && isspace(str[end]))
	{
		end--;
	}

	length = end - start + 1;

	memmove(str, str + start, length);
	str[length] = '\0';
	return (str);
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @str: string to search
 * @charset: set of bytes to search for
 * Return: pointer to the byte in str that matches one of the bytes in charset
 */
char *_strpbrk(const char *str, const char *charset)
{
	const char *c;

	for (; *str != '\0'; str++)
	{
		for (c = charset; *c != '\0'; c++)
		{
			if (*str == *c)
			{
				return ((char *)str);
			}
		}
	}
	return (NULL);
}

