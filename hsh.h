#ifndef HSH_H
#define HSH_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

/*prototype function*/
void terminal(char **argv, char **env);
char **parse_paths();
char *check_path(char **paths, char *cmd);
void custom_exit(void);
void custom_env(char **env);
void fork_function(char *st, char **argv, char *arg_arr[], char **env, int id);
void custom_free(char *st, int __status);
void check_p_l(char **p_l, int idx, char *arg_arr[], char **argv, char **env);

#endif
