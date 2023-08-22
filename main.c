#include "main.h"
/**
 * main - the main function of simplshell
 *
 * Return: Always 0.
 */
int main(void)
{
	char *cmd = NULL;
	size_t cmd_taille = 0;
	ssize_t lire;
	int inter = isatty(STDIN_FILENO);

	while (1)
	{
		if (inter) /* check intractive mode */
			prompt();

		lire = getline(&cmd, &cmd_taille, stdin);
		if (lire == -1)
		{
			if (inter)
				printf("\n");
			free(cmd);
			break;
		}

		cmd[lire - 1] = '\0'; /* replace the newline (pressing the Enter key) */

		if (strlen(cmd) == 0)
			continue;

		if (strcmp(cmd, "exit") == 0)
			break;

		if (strcmp(cmd, "env") == 0)
			print_env();

		exe_cmd_args(cmd);
	}
	return (0);
}
