#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
#define MAX_C 10
/**
 * struct denum - structure that contains vars
 * @cnt: lines cnt
 */
typedef struct denum
{
	int cnt;
} denum;

/*prototype functions*/

/*----------error_handle.c----------*/
void foundError(denum *n, char **arv, char *cmd);

/*----------terminal.c----------*/
void shell_main(char **arv, char **envp, bool flg);
void runcmd(char **rgv, char **arv, char **envp);
int exit_control(char *cmd);

/*----------string_handle.c----------*/
int compare_string(char *s1, char *s2);
int length_string(char *s);
char *srctodest(char *dest, char *src);
char *copystring(char *dest, char *src);

/*----------string_manipulation_handle.c----------*/
char *remove_space(char *cmd);
char *stringncopy(char *dest, char *src, int n);

/*------------------------------*/
char *path_control(char **rgv, char *cmd);

#endif

