#ifndef MAIN_H
#define MAIN_H

void nmode();
void imode();
char *_strcat(char *src, char *dest);
char **tokenizer(char *str);
int fork_process(char *buffer, char **args);
int engine(char *exec_name);
#endif
