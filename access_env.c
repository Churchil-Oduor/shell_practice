#include <stdio.h>

/**
 * main - access the environment variables.
 * @ac: total count of passed params.
 * @args: arrays of strings comprising of passed params.
 * @env: envrironment variables.
 * Return: always a 0.
 */

int main(int ac, char *args[], char *env[])
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
