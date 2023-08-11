#include "main.h"
/**
 * main - the main function of simplshell
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid;
	char cmd[100];
	int inter = isatty(STDIN_FILENO); /*for interactive mode*/

	while (1)
	{
		if (inter)
			prompt();
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			if (inter == 1)
				printf("\n");
			break;
		}

		cmd[strcspn(cmd, "\n")] = '\0';

		if (strlen(cmd) == 0)
			continue;

		pid = fork();

		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			execlp(cmd, cmd, NULL);
			perror(cmd);
			exit(1);
		}
		else
			waitpid(pid, NULL, 0);
	}
	return (0);
}
