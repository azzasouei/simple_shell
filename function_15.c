#include "shell.h"

/**
 * fun70 - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int fun70(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = fun54(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = fun34(&(info->alias),
		fun30(info->alias, fun29(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * fun71 - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int fun71(info_t *info, char *str)
{
	char *p;

	p = fun54(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (fun70(info, str));

	fun70(info, str);
	return (fun32(&(info->alias), str, 0) == NULL);
}

/**
 * fun72 - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int fun72(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = fun54(node->str, '=');
		for (a = node->str; a <= p; a++)
			fun11(*a);
		fun11('\'');
		fun10(p + 1);
		fun10("'\n");
		return (0);
	}
	return (1);
}

/**
 * fun73 - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int fun73(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			fun72(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = fun54(info->argv[i], '=');
		if (p)
			fun71(info, info->argv[i]);
		else
			fun72(fun29(info->alias, info->argv[i], '='));
	}

	return (0);
}

/**
 * fun74 - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int fun74(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = fun55(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			fun56(info, "Illegal number: ");
			fun60(info->argv[1]);
			fun61('\n');
			return (1);
		}
		info->err_num = fun55(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

