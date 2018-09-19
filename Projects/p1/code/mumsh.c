/*************************************************************************
    > File Name: mumsh.c
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-09-16 18:23:13
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<wait.h>
#include "cmdl.h"

int main(){
	while (1){
		printf("mumsh $ ");
		char command[1024]={0};
	    fgets(command,1024,stdin);
		const char *esc="exit";
		if (strcmp(command,"\n")==0) continue;
		command[strlen(command)-1]=0;
		if (strcmp(command,esc)==0) break;
		cmdl line_parsed = parse(command);
		pid_t pid = fork();
		if (pid==0) exec_cmdl(line_parsed);
		else waitpid(pid,NULL,0);
		cmdl_clean(line_parsed);
	}
	return 0;
}
