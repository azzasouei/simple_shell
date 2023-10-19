#ifndef HSH_H
#define HSH_H

void terminal(char **argv, char **env);
char **parse_paths();
char *check_path(char **paths, char *cmd);
void custom_exit(void);
void custom_env(char **env);

#endif
