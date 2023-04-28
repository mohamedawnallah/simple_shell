#include <string.h>
#include "simple_shell.h"

/**
 * Parses command and arguments from string
 */
void parse_command(char *command, char **args)
{
	int i = 0;

	args[i++] = strtok(command, " ");

	while (args[i - 1] != NULL && i < MAX_COMMAND_LENGTH / 2)
	{
		if (args[i - 1][0] == '#')
		{
			args[i - 1] = NULL;
			break;
		}
		args[i++] = strtok(NULL, " ");
	}
	args[i] = NULL;
}
