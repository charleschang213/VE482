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
#include "backtab.h"
static pid_t son;
static pid_t pid;
static backtab table;
void handler(int sig){

	if ((sig==SIGINT)&&(son==0)){
	    if (pid!=0) printf("\n");
		fflush(stdout);
		exit(0);
	}
	pid_t killsleep = fork();
	if (killsleep==0){
		char *ags[] = {"pkill","sleep",NULL};
		execvp("pkill",ags);
	}
	else waitpid(killsleep,NULL,0);
	waitpid(son,NULL,0);
	signal(SIGINT,handler);
}


int main(){
	bt_init(&table);
	int fd[2];
	int fd2[2];
	int fd3[2];
	int lastquote;
	signal(SIGINT,handler);
	while (1){
		lastquote = 0;
		fflush(stdout);
		pid = -1;
		pipe(fd);
		pipe(fd2);
		pipe(fd3);
		son = fork();
		if (son==0){
			bt_clean(&table);
			close(fd[0]);
			close(fd2[0]);
			close(fd3[0]);
			char a;
			char **quotelist = malloc(20*sizeof(char*));
			for (int i=0;i<20;i++) {
				quotelist[i] = malloc(20*sizeof(char));
				for (int j=0;j<20;j++) quotelist[i][j]=0;
			}
			clearerr(stdin);
			fseek(stdin,0,SEEK_SET);
			setbuf(stdin,NULL);
			printf("mumsh $ ");
			fflush(stdout);
			char command[1024]={0};
			int flag=0;
			a = getchar();	
			if (a=='\n') {
				command[0] = a;
				int send = 1;
				write(fd[1],&send,4);
				write(fd[1],command,1);
				close(fd[1]);
				close(fd2[1]);
				close(fd3[1]);
				for (int i=0;i<20;i++) free(quotelist[i]);
				free(quotelist);
				exit(0);
			}
			if (feof(stdin)) {
				int send = -1;
				write(fd[1],&send,4);
				close(fd[1]);
				close(fd2[1]);
				close(fd3[1]);
				for (int i=0;i<20;i++) free(quotelist[i]);
				free(quotelist);
				exit(1);
			}
			const char *cdd = "cd";
			const char *jobs = "jobs";
			int quotemode = 0;
			int backmode = 0;
			int waitmode = 0;
			int quoteflag = -1;
			int init=0;
			if ((a=='>')||(a=='<')) waitmode=1;
			if ((a=='\"')||(a=='\'')) {
				quoteflag++;
				quotemode=1;
			}
			//fflush(stdin);
			/*while ((a!='\n')&&(!feof(stdin))){
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
			}*/
			while ((!feof(stdin))){
				command[flag]=a;
				if (strcmp(command,cdd)==0){
					int send = -2;
					write(fd[1],&send,4);
					close(fd[1]);
					close(fd2[1]);
					close(fd3[1]);
					for (int i=0;i<20;i++) free(quotelist[i]);
					free(quotelist);
					exit(2);
				}
				if (strcmp(command,jobs)==0){
					int send = -3;
					write(fd[1],&send,4);
					close(fd[1]);
					close(fd2[1]);
					close(fd3[1]);
					getchar();
					for (int i=0;i<20;i++) free(quotelist[i]);
					free(quotelist);
					exit(3);
				}
				flag++;
				a = getchar();
				init=0;
				while (a==EOF){
					clearerr(stdin);
					a = getchar();
				}
				if ((quotemode==0)&&(a=='\"')) {
					quotemode = 1;
					init = 1;
					quoteflag++;
				}
				else if ((quotemode==0)&&(a=='\'')) {
					quotemode = 2;
					init = 1;
					quoteflag++;
				}
				else if (((quotemode==1)&&(a=='\"'))||((quotemode==2)&&(a=='\''))) {
					int nospace=0;
					int where;
					for (where = flag-1;command[where]!=a;where--){
						if (command[where]==' ') nospace=1;
					}
					if (nospace==0){
						for (int i=where;i<flag-1;i++) command[i] = command[i+1];
						a = command[flag-2];
						command[flag-2]  = 0;
						command[flag-1] = 0;
						flag-=2;
						int len = strlen(quotelist[quoteflag]);
						for (int i=0;i<len;i++) quotelist[quoteflag][i]=0;
						quoteflag--;
					}
					quotemode = 0;
					continue;
				}
				if ((quotemode!=0)&&(init==0)) quotelist[quoteflag][strlen(quotelist[quoteflag])] = a;
				if (((a=='>')||(a=='<')||(a=='|'))&&(!((a=='>')&&(command[flag-1]=='>')))){
					if ((waitmode==1)&&(quotemode==0)){
						int find;
						for (find=flag-1;command[find]==' ';find--);
						if ((command[find]=='|')&&(a=='|'))
							printf("error: missing program\n");
						else
							printf("syntax error near unexpected token `%c\'\n",a);
						fflush(stdout);
						while (a!='\n') a = getchar();
						int send = -4;
						write(fd[1],&send,4);
						close(fd[1]);
						close(fd2[1]);
						close(fd3[1]);
						for (int i=0;i<20;i++) free(quotelist[i]);
						free(quotelist);
						exit(4);
					}
					if (quotemode==0) waitmode = 1;
					if (quotemode==1) {
						command[flag] = '\\';
						flag++;
						command[flag] = 's';
						flag++;
						a = (a=='<')?'1':((a=='>')?'2':'3');
					}
				}
				else if (a=='\n'){
					if ((waitmode==0)&&(quotemode==0)) break;
					printf("> ");
					fflush(stdout);
					if (quotemode==0) a = ' ';
				}
				else if (a!=' ') waitmode=0;
				//printf("%s - %d\n",command,quotemode);
			}
			const char *esc="exit";
			//if (feof(stdin)) exit(1);
			//if (strcmp(command,"\n")==0) exit(0);
			//command[strlen(command)-1]=0;
			if (strcmp(command,esc)==0) {
				int send = -1;
				write(fd[1],&send,4);
				close(fd[1]);
				close(fd2[1]);
				close(fd3[1]);
				for (int i=0;i<20;i++) free(quotelist[i]);
				free(quotelist);
				exit(1);
			}
			int send = strlen(command);	
			write(fd[1],&send,4);	
			close(fd[1]);
			if (command[strlen(command)-1]=='&') {
				backmode = 1;
				command[strlen(command)-1]=0;
			}
			cmdl line_parsed = parse(command,quotelist);
			if (line_parsed.outdup==1){
				printf("error: duplicated output redirection\n");
				cmdl_clean(line_parsed);
				write(fd2[1],command,strlen(command));
				close(fd2[1]);
				for (int i=0;i<20;i++) free(quotelist[i]);
				free(quotelist);
				exit(0);
			}
			if (line_parsed.indup==1){
				printf("error: duplicated input redirection\n");
				cmdl_clean(line_parsed);
				write(fd2[1],command,strlen(command));
				close(fd2[1]);
				for (int i=0;i<20;i++) free(quotelist[i]);
				free(quotelist);
				exit(0);
			}
			/*for (int i=0;i<line_parsed.cmdc;i++){
				if (line_parsed.commands[i].argc==0){
					printf("error: missing program\n");
					fflush(stdout);
					exit(0);
				}
			}*/
			for (int i=0;i<20;i++) free(quotelist[i]);
			free(quotelist);
			/* if (strcmp(line_parsed.commands[0].argv[0],cdd)==0){
				chdir(line_parsed.commands[0].argv[1]);
				cmdl_clean(line_parsed);
				exit(0);
			}*/	
			if (backmode==1) command[strlen(command)] = '&';
			write(fd2[1],command,strlen(command));
			close(fd2[1]);
			pid = fork();
			if (pid==0) exec_cmdl(line_parsed,backmode,table.num,command,fd3);
			else {
				close(fd3[1]);
				waitpid(pid,NULL,0);
			}
			cmdl_clean(line_parsed);
			exit(0);
		}
		else {
			close(fd[1]);
			close(fd2[1]);
			close(fd3[1]);
			int *status=malloc(sizeof(int));
			read(fd[0],status,4);
			if (*status<0){
				close(fd[0]);
				close(fd2[0]);
				close(fd3[0]);
				waitpid(son,status,0);
				if (*status==256) {
					free(status);
					printf("exit\n");
					bt_clean(&table);
					exit(0);
				}
				else if (*status==512) {
					char *address = malloc(100*sizeof(char));
					scanf("%s",address);
					int result = chdir(address);
					if (result==-1) {
						printf("%s: No such file or directory\n",address);
						fflush(stdout);
					}
					free(address);
					free(status);
				}
				else if (*status==768) {
					bt_show(&table);
					free(status);
				}
				else free(status);
			}
			else{
				close(fd[0]);
				char command[1024]={0};
				read(fd2[0],command,*status);
				close(fd2[0]);
				if ((strlen(command)!=0)&&(command[strlen(command)-1]=='&')) {
					int tt;
					read(fd3[0],&tt,4);
					close(fd3[0]);
					bt_append(&table,son,command);
				}
				else {
					close(fd3[0]);
					waitpid(son,status,0);
				}
				free(status);
			}
		}
	}
	return 0;
}
