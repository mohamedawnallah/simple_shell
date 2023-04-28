#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "simple_shell.h"

/**
 * Entry point for simple shell
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_COMMAND_LENGTH / 2 + 1];

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("simple_shell$ ");
		}

		fgets(command, MAX_COMMAND_LENGTH, stdin);

		remove_newline(command);

		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}

		parse_command(command, args);

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

	return (0);
}
