/*************************************************************************
    > File Name: cmdl.h
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-09-16 19:02:40
 ************************************************************************/

#ifndef CMDL_H
#define CMDL_H
#define _DEFAULT_SOURCE
#define _POSIX_SOURCE
#include<sys/types.h>
#include <signal.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>
#include "funcs.h"
#include "backtab.h"
typedef struct _cmd_{
	int argc;
	char **argv;
	char *irdr,*ordr;
	int append_o;
}cmd;

static int youexit;
typedef struct _cmdl_{
	int cmdc;
	int indup,outdup;
	cmd *commands;
}cmdl;
cmdl parse(char* str,char** quotelist);
void cmdl_clean(cmdl line);
int exec_cmdl(cmdl line,int backmode,int num,char *command,int *fd3);
#endif
