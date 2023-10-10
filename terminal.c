#include "hsh.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

void terminal(char** argv, char** env)
{
        char* st = NULL;
        int idx = 0;
        int status = 0;
        size_t n = 0;
        ssize_t number_of_caracters;
        
	char* arg_arr[] = {NULL, NULL};
        char** path_list;
        char* new_path;
        char* delim = " ";
        pid_t child;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf(":) ");
		}

		number_of_caracters = getline(&st, &n, stdin);

		if (number_of_caracters == -1)
		{
			free(st);
			exit(EXIT_FAILURE);
}
while(st[idx])
{
	if (st[idx] == '\n')
	{
		st[idx] = 0;
	}
	++idx;
}
idx = 0;
arg_arr[idx] = strtok(st, delim);
if (strcmp(arg_arr[idx], "exit") == 0)
{
	custom_exit();
}
else if (strcmp(arg_arr[idx], "env") == 0)
{
	custom_env(env);
	continue;
}
while(arg_arr[idx])
{
	++idx;
	arg_arr[idx] = strtok(NULL, delim);
}
child = fork();
if(child == -1)
{
	free(st);
	exit(EXIT_FAILURE);
}
}
else if (child == 0)
{
if (access(arg_arr[0], X_OK) == 0)
{
if (execve(arg_arr[0], arg_arr, env) == -1)
{  
	printf("%s :No such file or directory\n", argv[0]);
}
}
else
{
	path_list = parse_paths();
	if (path_list == NULL)
	{
		printf("%s :No such file or directory\n", argv[0]);
	}
	else
	{
		new_path = check_path(path_list, arg_arr[0]);
		if (new_path == NULL)
		{
			printf("%s :No such file or directory\n", argv[0]);
		}
		else
		{
			if (execve(new_path, arg_arr, env) == -1)
			{
				printf("%s :No such file or directory\n", argv[0]);
			}
			free(new_path);
		}
                                        idx = 0;
                                        while(path_list[idx] != NULL)
{
                                                free(path_list[idx]);
                                                ++idx;
                                        }
                                        free(path_list);
                                }
                        }
}
else
{
			wait(&status);                                                                                                                
		}
}
}

char** parse_paths()
{
	char** paths;
	char* cp_var;
	char* var;
	char* token;
	int number_of_paths = 1;
	int path_len;
	int i = 0;

	var = getenv("PATH");
	if (!var)
		return NULL;

	cp_var = strdup(var);
if (!cp_var)
	return NULL;

path_len = strlen(cp_var);
	for (i = 0; i < path_len; ++i)
	{
		if (cp_var[i] == ':')
		{
			number_of_paths++;
		}
	}
	paths = malloc((number_of_paths + 1) * sizeof(char*));
	token = strtok(cp_var, ":");
	i = 0;
	while (token)
	{
		paths[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(paths[i], token);
		token = strtok(NULL, ":");
		i++;
	}
	return paths;
}
char* check_path(char** paths, char* cmd)
{
int i = 0;
bool found = false;
char* new_path = NULL;

while(paths[i] != NULL)
{
	new_path = malloc((strlen(paths[i]) + strlen(cmd) + 1) * sizeof(char));
strcpy(new_path, paths[i]);
strcat(new_path, "/");
		strcat(new_path, cmd);

		if (access(new_path, X_OK) == 0)
		{
			found = true;
			break;
             }
		free(new_path);
		++i;
        }

	return (found ? new_path : NULL);
}
