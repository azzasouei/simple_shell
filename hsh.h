#ifndef HSH_H
#define HSH_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

void terminal(char **argv, char **env);
char **parse_paths();
char *check_path(char **paths, char *cmd);
void custom_exit(void);
void custom_env(char **env);

#endif
