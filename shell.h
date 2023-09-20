#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_DISPLAY_LENGTH 100
#define MAXIMUM_COMMAND 100

int take_cmd(char *prmpt);
void parse_prmpt(char *prmpt, char **command);
void exec_prmpt(char **command);
char *myown_strcat(char *dest, const char *src);
size_t cust_strlen(const char *inpstr);
int c_strcmp(const char *s1t, const char *s2t);
char *concat_str(char *destination, const char *source);

//functions for environment variables//	
void prnt_environ(void);
char *_cust_getenv(const char *argname)

#endif

