#include "shell.h"

/**
 * compare_string - a function that compares two strings.
 * @s1: first string
 * @s2: second string
 * Return: 0 if strings are equal, otherwise a non-zero value.
 */
int compare_string(char *s1, char *s2)
{
	int cmp = 0;

	for (; *s1 == *s2 && *s1 != '\0'; s1++, s2++)
	{

	}

	if (*s1 != *s2)
		cmp = *s1 - *s2;

	return (cmp);
}

/**
 * length_string - a function that calculates the length of a string.
 * @s: the input string
 * Return: the length of the string.
 */
int length_string(char *s)
{
	int length = 0;

	for (; *(s + length) != '\0'; length++)
	{

	}

	return (length);
}


/**
 * srctodest - This function appends the src string to the dest string.
 * @dest: string argument
 * @src: string argument
 * Return: String
 */
char *srctodest(char *dest, char *src)
{
	int len = 0, lend = 0, j;

	for (; src[len] != '\0'; len++)
	{

	}

	for (; dest[lend] != '\0'; lend++)
	{

	}

	for (j = 0; j < len; j++)
	{
		dest[lend + j] = src[j];
	}
	dest[lend + len] = '\0';

	return (dest);
}


/**
 * copystring - copy a string
 * @dest: dest string arg
 * @src: source arg
 * Return: string value
 */
char *copystring(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; len++)
	{
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * string_compare - compares n bytes in str1 and str2
 * @str1: first string to be compared
 * @str2: second string to be compared
 * @n: number of bytes to be checked
 * Return: > 0 if str2 is less than str1, < 0 if str1 < str2,
 * 0 if str1 is equal to str2
 */
int string_compare(char *str1, char *str2, int n)
{
	if (!n)
		return (0);
	if (*str1 == *str2)
		return (*str1 ? string_compare(str1 + 1, str2 + 1, n - 1) : 0);
	if (*str1)
		return (1);
	if (*str2)
		return (-1);
	return (*str1 - *str2);
}

