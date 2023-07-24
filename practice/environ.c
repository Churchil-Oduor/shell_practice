#include <stdio.h>
#include <stdlib.h>


/**
 * main - prints the environment variables using environ variable.
 * Return: Always a zero.
 */

int main()
{
	extern char **environ;
	char **list;
	int i;

	list = environ;
	i = 0;

	while (list[i] != NULL)
	{
		printf("%s\n", list[i]);
		i++;
	}

	return (0);
}
