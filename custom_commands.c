#include "hsh.h"

#include <stdio.h>
#include <stdlib.h>

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
