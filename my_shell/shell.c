#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
/**
 * main - implementtation of simple shell project practice.
 * @ac: number of items passed via the command line.
 * @args: array of strings passed onto the command line.
 * Return: Always a 0.
 */

int main(int ac, char **argv)
{
	char *command;
	ssize_t bytes_read, len;
	int res_exec, count;

	len = 0;
	count = 0;
	command = NULL;
	bytes_read = 0;
	const char delimiters[] = " ";
	while (bytes_read != EOF)
	{
		char *args[1024] = {""};
		char path[1024] = "/bin/";
		printf("($) ");
		bytes_read = getline(&command, &len, stdin);

		if (bytes_read == -1)
			perror("Error Could not read Command");

		char *token = strtok(command, delimiters);
		while (token != NULL)
		{
			args[count] = token;
			count++;
			token = strtok(NULL, delimiters);
			printf("%s\n", token);
		}

		res_exec = execve(argv[0], args, NULL);

		if (res_exec == -1)
			perror("An Error Ocuured");
	}


	printf("\nTerminated Successfully\n");
	return (0);
}


