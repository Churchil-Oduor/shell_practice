#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
void nmode(char **env);
void imode(char **env);
char *_strcat(char *src, char *dest);
char **tokenizer(char *str);
int fork_process(char *buffer, char **args);
int engine(char *buffer, char **env);
#endif
