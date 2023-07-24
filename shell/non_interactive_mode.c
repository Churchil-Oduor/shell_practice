#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#define BUFFER_SIZE 1024

/**
 * nmode - this is the non_interactive mode
 * code.
 *
 * @exec_name: name of our executable file.
 */

void nmode(char *exec_name)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_bytes, res_exec;
	char **args;
	char path[BUFFER_SIZE] = "/bin/";

	read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE) - 1;
	args = malloc(sizeof(args) * BUFFER_SIZE);

	if (read_bytes > 0)
	{
		/** Null terminating the string read at the end**/
		buffer[read_bytes] = '\0';
		engine(buffer);
	}
	else
	{
		perror("Error Ocurred reading terminal");
	}
}


