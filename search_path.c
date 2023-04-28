#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * Searches for the path of a given command in the directories specified
 */
char *search_path(char *command)
{
char *path = getenv("PATH");
char *path_copy = strdup(path);
char *dir = strtok(path_copy, ":");
char *command_path = NULL;
while (dir != NULL)
{
char *temp_path = malloc(strlen(dir) + strlen(command) + 2);
sprintf(temp_path, "%s/%s", dir, command);
if (access(temp_path, X_OK) == 0)
{
command_path = temp_path;
break;
}
free(temp_path);
dir = strtok(NULL, ":");
}
free(path_copy);
return (command_path);
}
