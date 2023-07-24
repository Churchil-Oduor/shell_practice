#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
/**
 * imode - this is the interactive mode.
 *
 * @args: string array passed through the terminal.
 */

void imode(char **args)
{
	char *buffer;
	ssize_t read_bytes, res_exec;
	char path[BUFFER_SIZE] = "/bin/";
	size_t len;

	len = 0;
	buffer = NULL;
	while (1)
	{

		printf("($) ");
		char **args = malloc(sizeof(args) * BUFFER_SIZE);
		read_bytes = getline(&buffer, &len, stdin);
		if (args == NULL)
		{
			perror("malloc could not allocate space");
			exit(1);
		}

		if (read_bytes == -1)
		{
			printf("\n");
			break;
		}
		buffer[read_bytes - 1] = '\0';
		engine(buffer);
		buffer = NULL;
	}
}
