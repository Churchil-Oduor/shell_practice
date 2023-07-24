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

void imode()
{
	char *line;
	ssize_t read_bytes;
	size_t len;

	len = 0;
	while (1)
	{

		line = NULL;
		printf("($) ");
		read_bytes = getline(&line, &len, stdin);

		if (read_bytes > 0 && line[read_bytes - 1] == '\n')
		{
			line[read_bytes - 1] = '\0';
		}
		else
		{
			printf("\n");
			break;
		}

		if (strcmp(line, "exit") == 0)
			break;
		engine(line);
	}
}
