#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define MAX_COMMAND_LENGTH 1024

extern char **environ;

void env_builtin(void);
void exit_builtin(int status);
void remove_newline(char *str);
void parse_command(char *command, char **args);
void execute_commands(char *commands);
void execute_command(char **args);

#endif /* SIMPLE_SHELL_H */
