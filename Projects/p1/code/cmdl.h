/*************************************************************************
    > File Name: cmdl.h
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-09-16 19:02:40
 ************************************************************************/

#ifndef CMDL_H
#define CMDL_H
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include "funcs.h"
typedef struct _cmd_{
	int argc;
	char **argv;
	char *irdr,*ordr;
	int append_o;
}cmd;

typedef struct _cmdl_{
	int cmdc;
	cmd *commands;
}cmdl;

cmdl parse(char* str);
void cmdl_clean(cmdl line);
void exec_cmdl(cmdl line);
#endif
