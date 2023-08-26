#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include"shell.h"
/**
 * main - this program gets input from getline and runs commandline
 * Description: This program displays a prompt, generates a child process
 * uses getline system call while reading input from stdin
 * the input becomes the path to the executable
 * Return: Always 0 (success)
 */

int main(void)
{
	char *cmd = NULL, prompt[] = "$ ";
	size_t n = 0;
	pid_t pid;
	ssize_t bytes = 0;
	/*struct stat statbuf;*/
	int status;
	char *argv[] = {NULL};

	/*print prompt on terminal with the $ sign*/
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

	/*read from stdin*/
	if (getline(&cmd, &n, stdin) == -1)
	{
	perror("Error (getline)");
	free(cmd);/* free memory if it fails*/
	exit(EXIT_SUCCESS);
	}
	/*replace newline character with null terminator*/
	if (bytes == -1)
	perror("Error");
	if (cmd[bytes - 1] == '\n')
	cmd[bytes - 1] = '\0';

	/*call fork and create a child process*/
	pid = fork();
	if (pid == -1)
	{
	perror("Error (fork)");
	exit(EXIT_SUCCESS);
	}
	if (pid == 0)/*child process*/
	execve(cmd, argv, NULL);
	
	/*parent process to wait*/
	if (waitpid(pid, &status, 0) == -1)
	{
	perror("Error (wait)");
	exit(EXIT_SUCCESS);
	}

	return (0);
}
