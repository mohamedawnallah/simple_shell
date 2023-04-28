#include <stdlib.h>
#include "simple_shell.h"

/**
 * Exits the shell
 */
void exit_builtin(int status)
{
	exit(status);
}
