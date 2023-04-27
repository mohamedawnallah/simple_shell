#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
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

		if (strcmp(args[0], "env") == 0)
		{
			env_builtin();
			continue;
		}

		execute_command(args);
	}

	return (0);
}

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

/**
 * Parses command and arguments from string
 */
void parse_command(char *command, char **args)
{
	int i = 0;

	args[i++] = strtok(command, " ");

	while (args[i - 1] != NULL && i < MAX_COMMAND_LENGTH / 2)
	{
		args[i++] = strtok(NULL, " ");
	}
	args[i] = NULL;
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
