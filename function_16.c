#include "shell.h"

/**
 * fun75 - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int fun75(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		fun10("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = fun65(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = fun65(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (fun13(info->argv[1], "-") == 0)
	{
		if (!fun65(info, "OLDPWD="))
		{
			fun10(s);
			fun11('\n');
			return (1);
		}
		fun10(fun65(info, "OLDPWD=")), fun11('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = fun65(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		fun56(info, "can't cd to ");
		fun60(info->argv[1]), fun61('\n');
	}
	else
	{
		fun51(info, "OLDPWD", fun65(info, "PWD="));
		fun51(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * fun76 - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int fun76(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	fun10("help call works. Function not yet implemented \n");
	if (0)
		fun10(*arg_array); /* temp att_unused workaround */
	return (0);
}

/**
 * fun77 - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int fun77(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * fun78 - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int fun78(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *fun79 - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int fun79(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

