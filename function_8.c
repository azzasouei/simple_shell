#include "shell.h"

/**
 * fun35 - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void fun35(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

/**
 * fun36 - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *fun36(info_t *info)
{
	char *buf, *dir;

	dir = fun65(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (fun12(dir) + fun12(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	fun8(buf, dir);
	fun15(buf, "/");
	fun15(buf, HIST_FILE);
	return (buf);
}

/**
 * fun37 - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int fun37(info_t *info)
{
	ssize_t fd;
	char *filename = fun36(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		fun63(node->str, fd);
		fun62('\n', fd);
	}
	fun62(-1, fd);
	close(fd);
	return (1);
}

/**
 * fun38 - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int fun38(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = fun36(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			fun39(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		fun39(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= 4096)
		fun34(&(info->history), 0);
	fun40(info);
	return (info->histcount);
}

/**
 * fun39 - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int fun39(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	fun32(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

