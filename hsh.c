#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	if (ac == 2)
	{
		fd = open(av[1], 00);
		if (fd == -1)
		{
			if (errno == 13)
				exit(126);
			if (errno == 2)
			{
				fun60(av[0]);
				fun60(": 0: Can't open ");
				fun60(av[1]);
				fun61('\n');
				fun61(-1);
				exit(127);
			}
			return (1);
		}
		info->readfd = fd;
	}
	fun68(info);
	fun38(info);
	terminal(info, av);
	return (0);
}

/**
 *fun80 - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int fun80(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

