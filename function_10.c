#include "shell.h"

/**
 * fun45 - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void fun45(__attribute__((unused))int sig_num)
{
	fun10("\n");
	fun10("$ ");
	fun11(-1);
}

/**
 * fun46 - initializes info_t struct
 * @info: struct address
 */
void fun46(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * fun47 - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void fun47(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = fun7(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = fun9(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		fun3(info);
		fun4(info);
	}
}

/**
 * fun48 - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void fun48(info_t *info, int all)
{
	fun20(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			fun35(&(info->env));
		if (info->history)
			fun35(&(info->history));
		if (info->alias)
			fun35(&(info->alias));
		fun20(info->environ);
			info->environ = NULL;
		fun25((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		fun11(-1);
	}
}

/**
 * fun49 - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **fun49(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = fun27(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

