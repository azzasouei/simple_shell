#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define HIST_FILE	".simple_shell_history"

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


int terminal(info_t *, char **);

int fun1(info_t *, char *, size_t *);
void fun2(info_t *, char *, size_t *, size_t, size_t);
int fun3(info_t *);
int fun4(info_t *);
int fun5(char **, char *);
char **fun6(char *, char);
char **fun7(char *, char *);
char *fun8(char *, char *);
char *fun9(const char *);
void fun10(char *);
int fun11(char);
int fun12(char *);
int fun13(char *, char *);
char *fun14(const char *, const char *);
char *fun15(char *, char *);
int fun16(info_t *);
void fun17(info_t *);
void fun18(info_t *);
char *fun19(char *, char, unsigned int);
void fun20(char **);
void *fun21(void *, unsigned int, unsigned int);
int fun22(info_t *, char *);
char *fun23(char *, int, int);
char *fun24(info_t *, char *, char *);
int fun25(void **);
size_t fun26(const list_t *);
char **fun27(list_t *);
size_t fun28(const list_t *);
list_t *fun29(list_t *, char *, char);
ssize_t fun30(list_t *, list_t *);
list_t *fun31(list_t **, const char *, int);
list_t *fun32(list_t **, const char *, int);
size_t fun33(const list_t *);
int fun34(list_t **, unsigned int);
void fun35(list_t **);
char *fun36(info_t *info);
int fun37(info_t *info);
int fun38(info_t *info);
int fun39(info_t *info, char *buf, int linecount);
int fun40(info_t *info);
ssize_t fun42(info_t *);
int fun44(info_t *, char **, size_t *);
void fun45(int);
void fun46(info_t *);
void fun47(info_t *, char **);
void fun48(info_t *, int);
char **fun49(info_t *);
int fun50(info_t *, char *);
int fun51(info_t *, char *, char *);
char *fun52(char *, char *, int);
char *fun53(char *, char *, int);
char *fun54(char *, char);
int fun55(char *);
void fun56(info_t *, char *);
int fun57(int, int);
char *fun58(long int, int, int);
void fun59(char *);
void fun60(char *);
int fun61(char);
int fun62(char c, int fd);
int fun63(char *str, int fd);
int fun64(info_t *);
char *fun65(info_t *, const char *);
int fun66(info_t *);
int fun67(info_t *);
int fun68(info_t *);
int fun69(info_t *);
int fun73(info_t *);
int fun74(info_t *);
int fun75(info_t *);
int fun76(info_t *);
int fun77(info_t *);
int fun78(char, char *);
int fun79(int);
int fun80(char *);

#endif

