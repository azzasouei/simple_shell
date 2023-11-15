#include "shell.h"

/**
 * fun25 - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int fun25(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

/**
 * fun26 - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t fun26(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * fun27 - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **fun27(list_t *head)
{
	list_t *node = head;
	size_t i = fun26(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(fun12(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = fun8(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * fun28 - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t fun28(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		fun10(fun58(h->num, 10, 0));
		fun11(':');
		fun11(' ');
		fun10(h->str ? h->str : "(nil)");
		fun10("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * fun29 - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *fun29(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = fun14(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

