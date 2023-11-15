#include "shell.h"

/**
 * terminal - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int terminal(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		fun46(info);
		if (fun77(info))
			fun10("$ ");
		fun61(-1);
		r = fun42(info);
		if (r != -1)
		{
			fun47(info, av);
			builtin_ret = fun16(info);
			if (builtin_ret == -1)
				fun17(info);
		}
		else if (fun77(info))
			fun11('\n');
		fun48(info, 0);
	}
	fun37(info);
	fun48(info, 1);
	if (!fun77(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * fun16 - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int fun16(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", fun74},
		{"env", fun64},
		{"help", fun76},
		{"history", fun69},
		{"setenv", fun66},
		{"unsetenv", fun67},
		{"cd", fun75},
		{"alias", fun73},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (fun13(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * fun17 - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fun17(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!fun78(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = fun24(info, fun65(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fun18(info);
	}
	else
	{
		if ((fun77(info) || fun65(info, "PATH=")
			|| info->argv[0][0] == '/') && fun22(info, info->argv[0]))
			fun18(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			fun56(info, "not found\n");
		}
	}
}

/**
 * fun18 - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fun18(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, fun49(info)) == -1)
		{
			fun48(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				fun56(info, "Permission denied\n");
		}
	}
}

/**
 **fun19 - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *fun19(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

