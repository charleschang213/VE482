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
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include "cmdl.h"
#include "funcs.h"
static pid_t son;
static pid_t pid;
void handler(int sig){
	if ((sig==SIGINT)&&(son==0)){
	    if (pid!=0) printf("\n");
		fflush(stdout);
		exit(0);
	}
	waitpid(son,NULL,0);
	signal(SIGINT,handler);
}
int main(){
	signal(SIGINT,handler);
	while (1){
		fflush(stdout);
		pid = -1;
		son = fork();
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
			const char *cdd = "cd";
			//fflush(stdin);
			while ((a!='\n')&&(!feof(stdin))){
				command[flag]=a;
				if (strcmp(command,cdd)==0){
					exit(2);
				}
				flag++;
				a = getchar();
				while (a==EOF){
					clearerr(stdin);
					a = getchar();
				}
				fflush(stdin);
			}
			const char *esc="exit";
			if (feof(stdin)) exit(1);
			if (strcmp(command,"\n")==0) exit(0);
			//command[strlen(command)-1]=0;
			if (strcmp(command,esc)==0) exit(1);
			cmdl line_parsed = parse(command);
			/* if (strcmp(line_parsed.commands[0].argv[0],cdd)==0){
				chdir(line_parsed.commands[0].argv[1]);
				cmdl_clean(line_parsed);
				exit(0);
			}*/
			pid = fork();
			if (pid==0) exec_cmdl(line_parsed);
			else waitpid(pid,NULL,0);
			cmdl_clean(line_parsed);
			exit(0);
		}
		else {
			int *status=malloc(sizeof(int));
			waitpid(son,status,0);
			if (*status==256) {
				free(status);
				printf("exit\n");
				exit(0);
			}
			else if (*status==512) {
				char *address = malloc(100*sizeof(char));
				scanf("%s",address);
				chdir(address);
				free(address);
			}
			free(status);
		}
	}
	return 0;
}
