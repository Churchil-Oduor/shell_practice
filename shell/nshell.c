#include <unistd.h>
#include <stdio.h>
#include "main.h"
#define BUFFER_SIZE 1024


/**
 * main - this is start of the shell
 *
 * @ac: total number of arguments passed.
 * @args: array of strings that has been passed.
 * @env: List of Environment variables.
 *
 * Return: Always a 0.
 */

int main(int ac, char **args, char **env)
{

	if (isatty(fileno(stdin)))
	{
		/** interactive mode **/
		imode(env);

	}
	else
	{
		/** non interactive mode **/
		nmode(args[0], env);

	}
	return (0);

}
