#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 1024
#define MAX_TOKENS 100


/**
 * tokenizer - this function creates an array
 * of strings from a string.
 *
 * @str: string to be tokenized.
 * Return: array of strings.
 */

char **tokenizer(char *str)
{
	char **args;
	int index;
	char *token;

	/** intializing space for args to hold the array of strings **/
	args = malloc(sizeof(char **) * (MAX_TOKENS));
	if (args == NULL)
	{
		perror("Error in malloc -> tokenizer file");
		exit(1);
	}

	/** creating the tokens again and filling them into args**/
	token = strtok(str, " ");
	index = 0;
	while (token != NULL)
	{
		char *new_token = malloc(sizeof(char *) * (strlen(token) + 1));

		if (new_token == NULL)
		{
			perror("Error in malloc -> tokenizer file");
			free(args);
			exit(1);
		}

		strcpy(new_token, token);
		args[index] = new_token;
		index++;
		token = strtok(NULL, " ");
	}

	args[index] = NULL;
	return (args);
}
