#include "shell.h"

/**
 *fun60 - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void fun60(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		fun61(str[i]);
		i++;
	}
}

/**
 * fun61 - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int fun61(char c)
{
	static int i;
	static char buf[1024];

	if (c == -1 || i >= 1024)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != -1)
		buf[i++] = c;
	return (1);
}

/**
 * fun62 - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int fun62(char c, int fd)
{
	static int i;
	static char buf[1024];

	if (c == -1 || i >= 1024)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != -1)
		buf[i++] = c;
	return (1);
}

/**
 *fun63 - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int fun63(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += fun62(*str++, fd);
	}
	return (i);
}

/**
 * fun64 - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int fun64(info_t *info)
{
	fun33(info->env);
	return (0);
}

