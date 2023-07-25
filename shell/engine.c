#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


/**
 * engine - runs the execve command and retturns
 * execution back to calling function safely.
 *
 * @buffer: input passed either in interractive or non-interactive mode.
 * @env: list of environment variables.
 * @mode: mode of operation. 1 is interactive mode
 * and 0 is non-interactive mode.
 *
 * Return: 0 if success or 1 on failure.
 */

int engine(char *buffer, char **env, int mode)
{
	char **args, *pathname, *buffer_copy;
	char **e_vars; /** to be initialized with env **/
	char prepend[BUFFER_SIZE] = "/bin/";
	int count;

	e_vars = env;
	pathname = malloc(sizeof(pathname) * BUFFER_SIZE);
	args = tokenizer(buffer);
	if (args == NULL || pathname == NULL)
	{
		perror("Malloc could not allocate space -> Engine");
		return (1);
	}
	pathname = args[0];
	if (strcmp(pathname, "env") == 0 || strcmp(pathname, "printenv") == 0)
	{
		count = 0;
		/** loop through passed env variables **/
		while (e_vars[count] != NULL)
			printf("%s\n", e_vars[count++]);
	}
	if (pathname[0] == '/')
	{
		if (mode == 1)
			fork_process(pathname, args, mode);
		else
			fork_process(pathname, e_vars, mode);
	}
	else
	{
		_strcat(prepend, pathname);

		if (mode == 1)
			fork_process(prepend, args, mode);
		else
			fork_process(pathname, e_vars, mode);
	}
	free(pathname);
	return (0);
}

/**
 * fork_process - creates a child that does execve and returns
 * processing back to parent process.
 *
 * @pathname: pathname to the executable in the environment.
 * @args: arguments passed.
 * @mode: mode of execution.
 *
 * Return: A 0 on succcess else 1.
 */

int fork_process(char *pathname, char **args, int mode)
{


	pid_t child;
	ssize_t res_exec;
	int status;

	child = fork();
	if (child < 0)
	{
		perror("Could not form child");
	}
	else if (child == 0)
	{
		/** child process **/
		if (mode == 0)
		{
			char prepend[BUFFER_SIZE] = "/bin/";

			_strcat(prepend, pathname);
			res_exec = execve(prepend, args, NULL);
		}
		else
		{
			res_exec = execve(pathname, args, NULL);
		}
		if (res_exec == -1)
		{
			if (mode == 1)
				printf("%s: No such file or directory\n", pathname);
			else
				printf("%s: 1: %s: not found\n", args[0], pathname);
			return (1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}



