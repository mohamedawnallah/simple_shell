#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "simple_shell.h"

extern char **environ;

/**
 * env_builtin - prints the current environment variables
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

int main(void)
{
char *line;
char *args[MAX_COMMAND_LENGTH / 2 + 1];
pid_t pid;
int status;

while (1)
{
	printf("simple_shell$ ");
	line = my_getline();

	if (!line)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	int i = 0;
	args[i++] = strtok(line, " ");

	while (args[i - 1] != NULL && i < MAX_COMMAND_LENGTH / 2)
	{
		args[i++] = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (strcmp(args[0], "env") == 0)
	{
		env_builtin();
		continue;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	} else
	{
		wait(&status);
	}

	free(line);
}

	return (0);
}

