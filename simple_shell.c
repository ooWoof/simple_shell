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
	char *cmd = NULL;
	/*char *delim = " \n";*/
	size_t n = 0;
	/*pid_t pid;*/
	int i = 0;
	/*char *argv = NULL;*/

	printf("$ ");

	/*read from stdin*/
	if (getline(&cmd, &n, stdin) == -1)
		return (-1);
	printf("input%ld\n", strlen(cmd));
	
	printf("%c", cmd[i]);
	i++;
	free(cmd);
	return (0);
}
/*
 * execute_command - this program executes command using execve
 * @-l: argument
 *
 * Return: Always 0 (success)
 */

int execute_command(char *argv, NULL)
{
	char *argv[] = -1;
	pid_t pid;
	/*program execution, set path*/
	char *argv[] = {"/bin/ls", -l, NULL}

	/*declare int variable*/
	int val = execve(argv[0], argv, NULL);

	/*call fork*/
	pid = fork();
	if (pid == -1)
	return (-1);

	if (pid == 0) /*child pid*/
	{
	int val = execve(argv[0], argv, NULL);

	if (val == -1)
		perror("Error");
	}
	else
	{
	wait(NULL);/*parent process*/
	printf("end of execve\n");
	return (0);
	}
}
