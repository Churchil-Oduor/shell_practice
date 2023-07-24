#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
/**
 * engine - runs the execve command and retturns
 * execution back to calling function safely.
 *
 * @buffer: input passed either in interractive or non-interactive mode.
 * Return: 0 if success or 1 on failure.
 */

int engine(char *buffer)
{
	char **args;
	char *pathname;
	char prepend[BUFFER_SIZE] = "/bin/";

	pathname = malloc(sizeof(pathname) * BUFFER_SIZE);
	args = tokenizer(buffer);

	if (args == NULL || pathname == NULL)
	{
		perror("Malloc could not allocate space");
		exit(1);
	}

	pathname = args[0];
	if (pathname[0] == '/')
	{
		fork_process(pathname, args);
	}
	else
	{
		_strcat(prepend, pathname);
		fork_process(prepend, args);
	}

	
}

/**
 * fork_process - creates a child that does execve and returns
 * processing back to parent process.
 */
int fork_process(char *pathname, char **args)
{
	pid_t child;
	ssize_t res_exec;
	int status;

	child = fork();
	if (child < 0)
	{
		perror("Could not form child");
	}
	else if(child == 0)
	{
		/** child process **/
		res_exec = execve(pathname, args, NULL);
		if (res_exec == -1)
		{
			printf("%s: No such file or directory\n", pathname);
		}

		exit(1);
	}
	else
	{
		wait(&status);
	}

	return (0);
}



