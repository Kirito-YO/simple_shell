#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void prompt(void);
void print_env(void);
void exe_cmd_args(char *cmd);

#endif
