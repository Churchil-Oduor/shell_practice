#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * main - this is start of the shell
 *
 * @ac: count of arguments passed.
 * @args: arguments passed.
 * @env: list of environment variables.
 *
 * Return: Always a 0.
 */

int main(int ac, char **args, char **env)
{
	int i;

	i = 0;
	if (isatty(fileno(stdin)))
	{
		/** interactive mode **/
		imode(env);
		for (i = 0; i < ac; i++)
		{
			args[i] = NULL;
		}
	}
	else
	{
		/** non interactive mode **/
		nmode(env);

	}
	return (0);

}
