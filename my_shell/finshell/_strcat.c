#include "main.h"

/**
 * _strcat - concatenates src to dest.
 * @dest: pointer to first string.
 * @src: pointer to second string.
 * Return: returns pointer to the resulting string.
 */

char *_strcat(char *dest, char *src)
{
	int count_dest, count_src;

	count_dest = 0, count_src = 0;
	while (*(dest + count_dest) != '\0')
	{
		++count_dest;
	}

	while (*(src + count_src) != '\0')
	{
		*(dest + count_dest) = *(src + count_src);
		++count_dest;
		++count_src;
	}

	return (dest);
}
