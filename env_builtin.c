#include <stdio.h>
#include "simple_shell.h"

/**
 * Prints the current environment variables
 */
void env_builtin(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
