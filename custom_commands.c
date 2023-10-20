#include "hsh.h"

/**
 * custom_exit-Exit the program gracefully.
 * Description: This function terminates
 * the program with a return status of 0.
 */
void custom_exit(void)
{
	exit(0);
}
/**
 * custom_env-Print the environment variables.
 * Description: This function prints the environment
 * variables to the standard output.
 * @env :array of environment variable strings.
 * Return: None.
 */
void custom_env(char **env)
{
	int i = 0;

	if (env == NULL)
		return;

	for (i = 0; env[i] != NULL; ++i)
	{
		printf("%s\n", env[i]);
	}
}


/**
 * custom_free - Deallocates memory previously
 * allocated using custom functions.
 * @st: A pointer to the memory to be deallocated.
 * @__status: Check function status
 * This function checks if the given pointer is not NULL and then
 * frees the memory it points to.
 */
void custom_free(char *st, int __status)
{
	free(st);
	exit(__status);
}

/**
 * check_p_l - Checks and executes a command within the
 * provided directory paths.
 * @p_l: A string representing the full path to the command.
 * @arg_arr: An array of strings representing command and its arguments.
 * @env: An array of strings representing environment variables.
 * @argv: An array of strings representing command-line arguments.
 * @idx: An index for the 'path_list' array.
 *
 * This function checks if the 'new_path' points to
 * a valid command and, if so, executes it.
 * It also handles any necessary memory cleanup.
 */
void check_p_l(char **p_l, int idx, char *arg_arr[], char **argv, char **env)
{
	char *new_path;

	if (p_l == NULL)
		printf("%s :No such file or directory\n", argv[0]);
	else
	{
		new_path = check_path(p_l, arg_arr[0]);
		if (new_path == NULL)
			printf("%s :No such file or directory\n", argv[0]);
		else
		{
			if (execve(new_path, arg_arr, env) == -1)
				printf("%s :No such file or directory\n", argv[0]);
			free(new_path);
		}
		idx = 0;
		while (p_l[idx] != NULL)
		{
			free(p_l[idx]);
			++idx;
		}
		free(p_l);
	}
}
