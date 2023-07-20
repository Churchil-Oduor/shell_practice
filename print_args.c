#include <stdio.h>

/**
 * main - prints all the passed params without using ac
 * @ac - number of passsed inputs.
 * @av: array of strings.
 * Return: always a zero
 */

int main(int ac, char **av)
{
	int len;
	char *string;

	len = 1;
	while (av[len] != NULL)
	{
		printf("%s\n ", av[len]);
		len++;
	}
	return (0);
}

