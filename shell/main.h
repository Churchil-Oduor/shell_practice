#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
void nmode(char **args);
void imode(char **env);
char *_strcat(char *src, char *dest);
char **tokenizer(char *str);
int fork_process(char *buffer, char **args, int mode);
int engine(char *buffer, char **env, int mode);
#endif
