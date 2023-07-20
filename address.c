#include <stdio.h>
#include <stdlib.h>


/**
 * main - prints the address of env and the address of environ.
 * Return: always a zero.
 */

int main(int ac, char **args, char **env)
{
	extern char **environ;
	printf("1. env-address -> %p\n2. environ-address -> %p\n", &env, &environ);
	return (0);
}
