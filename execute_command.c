#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * Execute Commands Function
*/
void execute_commands(char *commands)
{
	char *token, *rest = commands;
	char *args[MAX_COMMAND_LENGTH / 2 + 1];

	while ((token = strtok_r(rest, ";", &rest)))
	{
		remove_newline(token);
		parse_command(token, args);

		if (strcmp(args[0], "exit") == 0)
		{
			int status = EXIT_SUCCESS;

			if (args[1] != NULL)
			{
				status = atoi(args[1]);
			}
			exit_builtin(status);
		}

		if (strcmp(args[0], "env") == 0)
		{
			env_builtin();
			continue;
		}

		execute_command(args);
	}
}

/**
 * Executes given command and arguments
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
