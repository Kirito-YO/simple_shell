#include "main.h"
/**
 * prompt - print the prompt of cmd line
 *
 * Return: NULL.
 */
void prompt(void)
{
    if (isatty(STDIN_FILENO))
    {
        printf("$ ");
        fflush(stdout);
    }
}

/**
 * exe_cmd_args - execute les cmds avec des arguments
 *
 * Return: NULL.
 */
void exe_cmd_args(char *cmd)
{
    char *args[100];
    int arg_compte = 0;
    pid_t pid;
    char *cp = strtok(cmd, " ");
	
    while (cp != NULL)
    {
        args[arg_compte] = cp;
        arg_compte++;
        cp = strtok(NULL, " ");
    }
    args[arg_compte] = NULL;

    pid = fork();

    if (pid == -1)
        perror("fork");
    else if (pid == 0)
    {
        execvp(args[0], args);
        perror(args[0]);
        exit(1);
    }
    else
        waitpid(pid, NULL, 0);
}
/**
 * print_env - print env variabl
 *
 * Return: NULL.
 */
void print_env(void)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
