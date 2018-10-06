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
#include<sys/wait.h>
#include "cmdl.h"
#include "funcs.h"

	
int main(){
	while (1){
		pid_t son = fork();
		if (son==0){
			char a;
			clearerr(stdin);
			fseek(stdin,0,SEEK_SET);
			setbuf(stdin,NULL);
			printf("mumsh $ ");
			fflush(stdout);
			char command[1024]={0};
			int flag=0;
			a = getchar();	
			if (a=='\n') exit(0);
			if (feof(stdin)) {
				exit(1);
			}
			//fflush(stdin);
			while ((a!='\n')&&(!feof(stdin))){
				command[flag]=a;
				flag++;
				a = getchar();
				while (a==EOF){
					clearerr(stdin);
					a = getchar();
				}
				fflush(stdin);
			}
			const char *esc="exit";
			const char *cdd = "cd";
			if (feof(stdin)) break;
			if (strcmp(command,"\n")==0) exit(0);
			//command[strlen(command)-1]=0;
			if (strcmp(command,esc)==0) exit(1);
			cmdl line_parsed = parse(command);
			if (strcmp(line_parsed.commands[0].argv[0],cdd)==0){
				chdir(line_parsed.commands[0].argv[1]);
				cmdl_clean(line_parsed);
				continue;
			}
			pid_t pid = fork();
			if (pid==0) exec_cmdl(line_parsed);
			else waitpid(pid,NULL,0);
			cmdl_clean(line_parsed);
			exit(0);
		}
		else {
			int *status=malloc(sizeof(int));
			waitpid(son,status,0);
			if (*status!=0) {
				free(status);
				break;
			}
			free(status);
		}
	}
	printf("exit\n");
	return 0;
}
