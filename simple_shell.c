#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "simple_shell.h"

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_COMMAND_LENGTH / 2 + 1];
    pid_t pid;
    int status;

    while(1) {
        // display prompt and read command
        printf("simple_shell$ ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // remove trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // exit on end of file
        if (feof(stdin)) {
            printf("\n");
            exit(EXIT_SUCCESS);
        }

	// handle exit command
	if (strcmp(command, "exit") == 0) {
            printf("Exiting shell...\n");
            exit(EXIT_SUCCESS);
        }

        // parse command and arguments
        int i = 0;
        args[i++] = strtok(command, " ");
        while (args[i - 1] != NULL && i < MAX_COMMAND_LENGTH / 2) {
            args[i++] = strtok(NULL, " ");
        }
        args[i] = NULL;

        // execute command
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // child process
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            // parent process
            wait(&status);
        }
    }

    return 0;
}
