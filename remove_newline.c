#include <string.h>
#include "simple_shell.h"

/**
 * Removes trailing newline character from string
 */
void remove_newline(char *str)
{
	if (str[strlen(str) - 1] == '\n')
	{
		str[strlen(str) - 1] = '\0';
	}
}
