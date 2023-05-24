#include "shell.h"

/**
 * get_directory_path - gets the directory path based on input
 * @directory: the directory input
 * Return: the directory path to change to
 */
char *get_directory_path(char *directory)
{
	if (directory == NULL)
	{
		char *path = getenv("HOME");

		if (path == NULL)
		{
			fprintf(stderr, "cd: No home directory\n");
			return (NULL);
		}
		return (strdup(path));
	}
	else if (_strcmp(directory, "-") == 0)
	{
		char *path = getenv("OLDPWD");

		if (path == NULL)
		{
			fprintf(stderr, "cd: Previous directory not set\n");
			return (NULL);
		}
		printf("%s\n", path);
		return (strdup(path));
	}
	else
	{
		return (strdup(directory));
	}
}

/**
 * change_directory - changes the current working directory
 * @path: the directory path to change to
 * Return: 0 on success, -1 on failure
 */
int change_directory(char *path)
{
	if (chdir(path) != 0)
	{
		perror("chdir");
		return (-1);
	}
	return (0);
}

/**
 * update_environment_variables - updates the environment variables
 * @current_dir: the current working directory
 * Return: 0 on success, -1 on failure
 */
int update_environment_variables(char *current_dir)
{
	if (_setenv("PWD", getcwd(NULL, 0), 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	if (setenv("OLDPWD", current_dir, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * builtin_cd - changes the current working directory
 * @directory: the directory to change to
 */
void builtin_cd(char *directory)
{
	char *path, *current_dir;

	path = get_directory_path(directory);
	if (path == NULL)
		return;
	current_dir = getcwd(NULL, 0);
	if (current_dir == NULL)
	{
		perror("getcwd");
		free(path);
		return;
	}
	if (change_directory(path) != 0)
	{
		free(current_dir);
		free(path);
		return;
	}
	if (update_environment_variables(current_dir) != 0)
	{
		free(current_dir);
		free(path);
		return;
	}
	free(current_dir);
	free(path);
}

