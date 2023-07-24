#include <unistd.h>
#include <stdio.h>
#include "main.h"
#define BUFFER_SIZE 1024

int main(int ac, char **args)
{

	if (isatty(fileno(stdin)))
	{
		/** interactive mode **/
		imode(args);

	}
	else
	{
		/** non interactive mode **/
		nmode(args[0]);

	}
	return (0);

}
