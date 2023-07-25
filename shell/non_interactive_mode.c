#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * nmode - this is the non_interactive mode code
 * @args: array of strings passed.
 *
 */

void nmode(char **args)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_bytes;
	int mode;

	read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE) - 1;
	mode = 0;

	if (read_bytes > 0)
	{
		/** Null terminating the string read at the end**/
		buffer[read_bytes] = '\0';
		engine(buffer, args, mode);
	}
	else
	{
		perror("Error Ocurred reading terminal");
	}
}


