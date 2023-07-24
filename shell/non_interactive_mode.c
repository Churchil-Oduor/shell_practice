#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * nmode - this is the non_interactive mode code
 * @env: list of environment variables
 *
 */

void nmode(char **env)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_bytes;

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


