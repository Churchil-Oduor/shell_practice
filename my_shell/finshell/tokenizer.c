#include "main.h"
#include <string.h>
#define BUFF_SIZE 1024
#include <stdlib.h>

/**
 * tokenizer - this function creates an array
 * of strings from a string.
 *
 * @str: string to be tokenized.
 * Return: array of strings.
 */

char **tokenizer(char *str)
{
	const char delimiters[] = " ";
	char **args;
	int num_tokens, index;

	char *token = strtok(str, delimiters);

	args = NULL;
	num_tokens = 0;

	/**Counting the number of tokens**/
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delimiters);
	}

	/** Allocating space to hold tokens **/
	args = malloc(sizeof(char **) * num_tokens);
	if (args == NULL)
		exit(1);

	/** creating the tokens again and filling them into args**/

	token = strtok(str, delimiters);
	index = 0;
	while (token != NULL)
	{
		args[index] = malloc(sizeof(char *) * (strlen(token) + 1));
		if (args[index] == NULL)
			exit(1);
		/** copying token into args at index -> index **/
		strcpy(args[index], token);
		index++;
		token = strtok(NULL, delimiters);
	}

	args[index] = NULL;

	return (args);

}
