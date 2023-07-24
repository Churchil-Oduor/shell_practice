#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#define BUFFER_SIZE 1024

/**
 * nmode - this is the non_interactive mode code
 *
 * @args: Arguments passed to the shell.
 * @env: list of environment variables
 */

void nmode(char *args, char **env)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_bytes;
	char path[BUFFER_SIZE] = "/bin/";

	read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE) - 1;

	if (read_bytes > 0)
	{
		/** Null terminating the string read at the end**/
		buffer[read_bytes] = '\0';
		engine(buffer, env);
	}
	else
	{
		perror("Error Ocurred reading terminal");
	}
}


