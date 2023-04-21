# simple_shell
The Simple Shell is a basic UNIX command line interpreter that allows you to execute simple commands with arguments. It's a minimalistic implementation that provides a basic prompt, parses commands and arguments, and executes them using the `execvp()` function.

## Usage
To use the Simple Shell, navigate to the directory containing the executable and run the program using the following command:
```bash
./simple_shell
```
This will start the Simple Shell and display the prompt:
```bash
simple_shell$
```
From here, you can type in a command followed by its arguments and press Enter to execute it. For example, to list the contents of a directory, you can use the `ls` command:
```bash
simple_shell$ ls /usr/bin
```
The Simple Shell will parse the command and its arguments, and execute it using `execvp()`. If the command is not recognized, the shell will display an error message and display the prompt again.
To exit the Simple Shell, simply type `exit` and press Enter. This will terminate the shell and return you to the command line.

## Limitations
The Simple Shell has some limitations and does not support advanced features such as pipes, redirection, or special characters. It is a basic implementation designed for educational purposes and can be used as a starting point for more advanced shell programs.
