#include "hsh.h"

/**
 *terminal-This function simulates a basic terminal that reads user input,
 *interprets and executes commands, and provides feedback.
 *@argv: A pointer to an array of strings representing command-line arguments.
 *@env: A pointer to an array of strings representing
 *the environment variables.
 *Return: This function does not return a value (void).
 */

/*
* tirm1 function,
*/
void tirm1(char **env)
{
	char *st = NULL;
	int idx = 0;
	char *arg_arr[] = {NULL, NULL};
	ssize_t number_of_caracters;
	char *delim = " ";
	size_t n = 0;

	if (isatty(STDIN_FILENO))
		printf(":) ");
	number_of_caracters = getline(&st, &n, stdin);
	if (number_of_caracters == -1)
	{
		free(st);
		exit(EXIT_FAILURE);
	}
	while (st[idx])
	{
		if (st[idx] == '\n')
		{
			st[idx] = 0;
		}
		++idx;
	}
	idx = 0;
	arg_arr[idx] = strtok(st, delim);
	if (strcmp(arg_arr[idx], "exit") == 0)
		custom_exit();
	if (strcmp(arg_arr[idx], "env") == 0)
	{
		custom_env(env);
		/*continue;*/
	}
	while (arg_arr[idx])
	{
		++idx;
		arg_arr[idx] = strtok(NULL, delim);
	}
}

/*
* _access function,
*/
void tirm2(char **argv, char **env)
{
	char *arg_arr[] = {NULL, NULL};
	int idx = 0;
	char *new_path;
	char **path_list;

	if (access(arg_arr[0], X_OK) == 0)
	{
		if (execve(arg_arr[0], arg_arr, env) == -1)
			printf("%s :No such file or directory\n", argv[0]);
	}
	else
	{
		path_list = parse_paths();
		if (path_list == NULL)
			printf("%s :No such file or directory\n", argv[0]);
		else
		{
			new_path = check_path(path_list, arg_arr[0]);
			if (new_path == NULL)
				printf("%s :No such file or directory\n", argv[0]);
			else
			{
				if (execve(new_path, arg_arr, env) == -1)
					printf("%s :No such file or directory\n", argv[0]);
				free(new_path);
			}
			idx = 0;
			while (path_list[idx] != NULL)
			{
				free(path_list[idx]);
				++idx;
			}
			free(path_list);
		}
	}
}

void terminal(char **argv, char **env)
{
	int status = 0;
	char *st = NULL;
	pid_t child;

	while (1)
	{
		tirm1(env);
		child = fork();
		if (child == -1)
		{
			free(st);
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			tirm2(argv, env);
		}
		else
			wait(&status);
	}
}

/**
 * parse_paths-This function parses the PATH environment variable
 * and returns an array of directory paths.
 * Return: A pointer to an array of strings containing directory paths,
 * or NULL if there was an error in parsing or memory allocation.
 */
char **parse_paths()
{
	char **paths;
	char *cp_var;
	char *var;
	char *token;
	int number_of_paths = 1;
	int path_len;
	int i = 0;

	var = getenv("PATH");
	if (!var)
		return (NULL);

	cp_var = strdup(var);

	if (!cp_var)
		return (NULL);

	path_len = strlen(cp_var);
	for (i = 0; i < path_len; ++i)
	{
		if (cp_var[i] == ':')
		{
			number_of_paths++;
		}
	}
	paths = malloc((number_of_paths + 1) * sizeof(char *));
	token = strtok(cp_var, ":");
	i = 0;
	while (token)
	{
		paths[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(paths[i], token);
		token = strtok(NULL, ":");
		i++;
	}
	return (paths);
}

/**
 * check_path-This function checks for the existence of a specified
 * command in the directories listed in the 'paths' array.
 * @paths: A pointer to an array of strings containing directory paths.
 *@cmd: A string representing the command to search for in the directories.
 *Return: pointer to a string containing the full path to the command if found
 *or NULL if the command is not found in any of the directories.
 */
char *check_path(char **paths, char *cmd)
{
	int i = 0;
	bool found = false;
	char *new_path = NULL;

	while (paths[i] != NULL)
	{
		new_path = malloc((strlen(paths[i]) + strlen(cmd) + 1) * sizeof(char));
		strcpy(new_path, paths[i]);
		strcat(new_path, "/");
		strcat(new_path, cmd);
		if (access(new_path, X_OK) == 0)
		{
			found = true;
			break;
		}
		free(new_path);
		++i;
	}
	return (found ? new_path : NULL);
}
