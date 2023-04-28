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

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("simple_shell$ ");
		}

		fgets(command, MAX_COMMAND_LENGTH, stdin);

		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}

		execute_commands(command);
	}
	return (0);
}
