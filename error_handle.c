#include "shell.h"

/**
 * int_length - a function that calculates the length of an integer.
 * @n: an integer parameter
 * Return: the length of the integer.
 */
int int_length(int n)
{
	unsigned int num;
	int len = 1;

	switch (n < 0)
	{
		case 1:
			len++;
			num = n * -1;
			break;
		default:
			num = n;
			break;
	}

	for (; num > 9; len++)
	{
		num = num / 10;
	}

	return (len);
}


/**
 * inttostr - a function that converts an integer to a string.
 * @num: the integer to be converted.
 * Return: a pointer to the resulting string.
 */
char *inttostr(int num)
{
	char *buff;
	size_t n;
	int len = int_length(num);

	buff = malloc(len + 1);
	if (!buff)
	{
		return (NULL);
	}
	buff[len] = '\0';
	if (num < 0)
	{
		n = num * -1;
		*buff = '-';
	}
	else
		n = num;
	len--;

	do {
		*(buff + len) = (n % 10) + '0';
		n /= 10;
		len--;
	} while (n > 0);
	return (buff);
}

/**
 * foundError - a function that
 * prints an error message for a command not found.
 * @n: argument
 * @arv: arv argument
 * @cmd: the command.
 * Return: void.
 */
void foundError(denum *n, char **arv, char *cmd)
{
	int len;
	char *errmsg, *cnt_str;

	cnt_str = inttostr(n->cnt);
	len = length_string(arv[0]) + length_string(cmd) +
	 length_string(cnt_str) + 17;
	errmsg = malloc(len);
	if (!errmsg)
	{
		return;
	}
	copystring(errmsg, arv[0]);
	srctodest(errmsg, ": ");
	srctodest(errmsg, cnt_str);
	srctodest(errmsg, ": ");
	srctodest(errmsg, cmd);
	srctodest(errmsg, ": not found\n");
	srctodest(errmsg, "\0");
	write(STDOUT_FILENO, errmsg, len);
	free(errmsg);
}


