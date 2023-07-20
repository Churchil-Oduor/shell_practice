#include <stdio.h>
#include <stdlib.h>


int main()
{
	char *buffer;
	size_t len;
	ssize_t read_len;

	len = 0;
	buffer = NULL;
	printf("$ ");
	read_len = getline(&buffer, &len, stdin);

	

	if (read_len == -1)
		printf("Nothing has been read\n");
	else
		printf("%s\n", buffer);

	free(buffer);
	
	return (0);
}
