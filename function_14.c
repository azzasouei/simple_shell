#include "shell.h"

/**
 * fun65 - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *fun65(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = fun14(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * fun66 - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int fun66(info_t *info)
{
	if (info->argc != 3)
	{
		fun60("Incorrect number of arguements\n");
		return (1);
	}
	if (fun51(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * fun67 - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int fun67(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		fun60("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		fun50(info, info->argv[i]);

	return (0);
}

/**
 * fun68 - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int fun68(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		fun32(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * fun69 - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int fun69(info_t *info)
{
	fun28(info->history);
	return (0);
}

