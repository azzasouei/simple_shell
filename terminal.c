#include "shell.h"

/**
 * sig_handler - handler cntrl c
 * @num: num argument
 */
void sig_handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n$ ", length_string("\n$ "));
}

/**
 * shell_main - a shell using c
 * @arv: argument by user
 * @envp: envirement variable argument
 * @flg: flag argument for mode
 */
void shell_main(char **arv, char **envp, bool flg)
{
	size_t n = 0;
	ssize_t num_c = 0;
	char *cmd = NULL, *rgv[MAX_C];
	int x;

	while (1)
	{
		if (flg && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", length_string("$ "));
		signal(SIGINT, sig_handler);
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1)
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		if (cmd[num_c - 1] == '\n')
			cmd[num_c - 1] = '\0';
		cmd = remove_space(cmd);
		if (length_string(cmd) == 0)
			continue;
		x = 0;
		rgv[x] = strtok(cmd, " \n");
		exit_control(cmd);
		path_control(rgv, cmd);
		while (rgv[x])
		{
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		runcmd(rgv, arv, envp);
	}
	free(cmd);
}

/**
 * runcmd - a function that run command
 * @rgv: rgv argument
 * @arv: arv argument
 * @envp: envp argument
 */
void runcmd(char **rgv, char **arv, char **envp)
{
	pid_t mychild;
	int stat;

	mychild = fork();

	if (mychild == -1)
	{
		perror("Process Error");
		exit(EXIT_FAILURE);
	}
	if (mychild == 0)
	{

		if (execve(rgv[0], rgv, envp) == (-1))
		{
			write(STDOUT_FILENO, arv[0], length_string(arv[0]));
			write(STDOUT_FILENO, ": No such file or directory",
			length_string(": No such file or directory"));
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&stat);
	}
}

/**
 * exit_control - function that terminate the prog when
 * user types "exit".
 * @cmd: the string to be read.
 * Return: nothing.
 *
 */
void exit_control(char *cmd)
{
	if (compare_string("exit", cmd) == 0)
	{
		free(cmd);
		exit();
	}
}

