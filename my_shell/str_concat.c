#include "main.h"
#include <stdlib.h>


/**
 * str_concat - concatenates two strings.
 * @str_1: first string.
 * @str_2: second_string.
 */

void *str_concat(char **str_1, char *str_2)
{
	int len_1, len_2, index, index_2;

	index = 0;
	index_2 = 0;

	while (str_2[index] != '\0')
	{
		str_1[0][index + 5] = str_2[index];
		index++;
	}
	return (str_1);
}


/**
 * _strlen - gets length of string.
 * @str: string whose length is to be found.
 * Return: length of string.
 */

int _strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;

	return (len);
}
