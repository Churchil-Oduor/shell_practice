#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that gets the environment variable.
 * Return: Always a zero.
 */

int main(int ac, char **args)
{
	const char *var;

	if (ac != 2)
		exit(100);
	var = getenv(args[1]);

	if (var != NULL)
		printf("%s\n", var);
	else
		printf("Could not find path");
	return (0);

}
