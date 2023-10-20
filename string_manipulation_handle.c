#include "shell.h"

/**
 * remove_space - remove space
 * @cmd: comand
 * Return: cmmand
 */
char *remove_space(char *cmd)
{
	char *cpcmd;
	int i = 0, len;

	while (cmd[i] == ' ')
		i++;
	len = length_string(cmd) - i + 1;
	cpcmd = malloc(len + 1);
	if (!cpcmd)
	{
		perror("Allocation Failed\n");
		return (NULL);
	}
	stringncopy(cpcmd, cmd + i, len);
	cpcmd[len] = '\0';
	copystring(cmd, cpcmd);
	free(cpcmd);
	return (cmd);
}

/**
 * Concantenates - Concantenates two strings where n number
 *            of bytes are copied from source.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: n bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *Concantenates(char *dest, const char *src, size_t n)
{
	size_t dest_len = length_string(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * stringncopy - copy n characters from src to dest
 * @dest: destination string argument
 * @src: source string argument
 * @n: integer argument
 * Return: dest
 */
char *stringncopy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}


/**
 * path_control - handle the path function
 * @rgv: rgv argument
 * @cmd: command set by the user
 * Return: command for exec
 */
char *path_control(char **rgv, char *cmd)
{
	char *path;

	path = malloc(length_string("/bin/") + length_string(cmd) + 1);
	if (!path)
	{
		return (NULL);
	}
	copystring(path, "/bin/");

	if (cmd[0] != '/' && cmd[0] != '.')
	{
		rgv[0] = srctodest(path, cmd);
		return (rgv[0]);
	}
	free(path);
	return (cmd);
}


