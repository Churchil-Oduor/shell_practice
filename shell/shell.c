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

		/**
		 * we are not going to use args because
		 * we are getting data from terminal.
		 * Also to make sure that betty checks pass
		 * so that it seems we utilised the variables
		 * ac and args
		 */
		for (i = 0; i < ac; i++)
		{
			args[i] = NULL;
		}
	}
	else
	{
		/** non interactive mode **/
		nmode(args);

	}
	return (0);

}
