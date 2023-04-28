#include <stdlib.h>
#include "simple_shell.h"

/**
 * Exits the shell
 */
void exit_builtin(char **args)
{
	if (args[1] != NULL)
	{
		int status = atoi(args[1]);

		exit(status);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
