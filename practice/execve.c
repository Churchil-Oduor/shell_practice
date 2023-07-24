#include <unistd.h>
#include <stdio.h>


/**
 * main - executes another program.
 * Return: always a  0.
 */

int main()
{
	char *path;

	path = "/bin/ls";
	char *args[] = {path, "-l", "/usr", NULL};

	if (execve(path, args, NULL) == -1)
	{
		printf("Error Occured");
		return (-1);
	}

	return (0);
}
