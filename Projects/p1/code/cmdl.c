/*************************************************************************
    > File Name: cmdl.c
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-09-16 19:54:25
 ************************************************************************/

#include "cmdl.h"

cmdl parse(char* str){
	char* ttmp = malloc((strlen(str)+1)*sizeof(char));
	strcpy(ttmp,str);
	cmdl newline;
	char **command_group;
	newline.cmdc = 0;
	newline.commands=NULL;
	command_group = malloc(sizeof(char*));
	char *tmp=strtok(ttmp,"|");
	while (tmp){
		newline.cmdc++;
		command_group = realloc(command_group,newline.cmdc*sizeof(char*));
		command_group[newline.cmdc-1] = malloc((strlen(tmp)+1)*sizeof(char));
		strcpy(command_group[newline.cmdc-1],tmp);
		tmp = strtok(NULL,"|");
	}
	newline.commands = malloc(newline.cmdc*sizeof(cmd));
	for (int i=0;i<newline.cmdc;i++){
		tmp = strtok(command_group[i]," ");
		newline.commands[i].argv = malloc(sizeof(char*));
		newline.commands[i].argc=0;
		newline.commands[i].append_o=0;
		newline.commands[i].irdr=newline.commands[i].ordr=NULL;
		while (tmp){
			/*if (tmp[0]=='<'){
				if (strcmp(tmp,"<")==0){
					tmp = strtok(NULL," ");
					newline.commands[i].irdr = malloc((strlen(tmp)+1)*sizeof(char));
					strcpy(newline.commands[i].irdr,tmp);
					tmp = strtok(NULL," ");
					continue;
				}
				char *tmpp = tmp+1;
				newline.commands[i].irdr = malloc((strlen(tmpp)+1)*sizeof(char));
				strcpy(newline.commands[i].irdr,tmpp);
				tmp = strtok(NULL," ");
				continue;
			}
			if (tmp[0]=='>'){
				if ((strcmp(tmp,">")==0)||(strcmp(tmp,">>")==0)){
					if (strcmp(tmp,">>")==0) newline.commands[i].append_o=1;
					tmp = strtok(NULL," ");
					newline.commands[i].ordr = malloc((strlen(tmp)+1)*sizeof(char));
					strcpy(newline.commands[i].ordr,tmp);
					tmp = strtok(NULL," ");
					continue;
				}
				int flag = 1;
				if (tmp[1]=='>') {
					newline.commands[i].append_o=1;
					flag=2;
				}
				char *tmpp = tmp+flag;
				newline.commands[i].ordr = malloc((strlen(tmpp)+1)*sizeof(char));
				strcpy(newline.commands[i].ordr,tmpp);
				tmp = strtok(NULL," ");
				continue;
			}*/
			char *inr = strstr(tmp,"<");
			char *outr = strstr(tmp,">");
			if (inr) *inr=0;
			if (outr) *outr=0;
			if ((tmp!=inr)&&(tmp!=outr)){
				newline.commands[i].argc++;
				newline.commands[i].argv = realloc(newline.commands[i].argv,newline.commands[i].argc*sizeof(char*));
				newline.commands[i].argv[newline.commands[i].argc-1]=malloc((strlen(tmp)+1)*sizeof(char));
				strcpy(newline.commands[i].argv[newline.commands[i].argc-1],tmp);
			}
			if (inr){
				if (inr[1]==0){
					tmp = strtok(NULL," ");
					newline.commands[i].irdr = malloc((strlen(tmp)+1)*sizeof(char));
					strcpy(newline.commands[i].irdr,tmp);
				}
				else{
					newline.commands[i].irdr = malloc((strlen(inr+1)+1)*sizeof(char));
					strcpy(newline.commands[i].irdr,inr+1);
				}
			}
			if (outr){
				if (outr[1]=='>'){
					outr++;
					newline.commands[i].append_o=1;
				}
				if (outr[1]==0){
					tmp = strtok(NULL," ");
					newline.commands[i].ordr = malloc((strlen(tmp)+1)*sizeof(char));
					strcpy(newline.commands[i].ordr,tmp);
				}
				else{
					newline.commands[i].ordr = malloc((strlen(outr+1)+1)*sizeof(char));
					strcpy(newline.commands[i].ordr,outr+1);
			
				}
			}
			tmp = strtok(NULL," ");
		}
		newline.commands[i].argv = realloc(newline.commands[i].argv,(newline.commands[i].argc+1)*sizeof(char*));
		newline.commands[i].argv[newline.commands[i].argc]=NULL;
	}
	for (int i=0;i<newline.cmdc;i++) free(command_group[i]);
	free(command_group);
	free(ttmp);
	return newline;
}

void cmdl_clean(cmdl line){
	for (int i=0;i<line.cmdc;i++){
		if (line.commands[i].irdr) free(line.commands[i].irdr);
		if (line.commands[i].ordr) free(line.commands[i].ordr);
		for (int j=0;j<line.commands[i].argc;j++) free(line.commands[i].argv[j]);
		free(line.commands[i].argv);
	}
	free(line.commands);
}

void exec_cmdl(cmdl line){
	if (line.cmdc==0) return;
	int **pipegroup = NULL;
	pid_t *pid = malloc(line.cmdc*sizeof(pid_t));
	for (int i=0;i<line.cmdc;i++) pid[i]=0xffff;
	if(line.cmdc>1){
		pipegroup = malloc((line.cmdc-1)*sizeof(int*));
		for (int i=0;i<line.cmdc-1;i++){
			pipegroup[i] = malloc(2*sizeof(int));
			pipe(pipegroup[i]);
		}
	}
	int flag=0;
	for (int i=0;i<line.cmdc;i++){
		if (flag==0) {
			pid[i] = fork();
		}
		if (pid[i]==0) {
			flag = i+1;
			if (flag!=1) {
				dup2(pipegroup[flag-2][0],STDIN_FILENO);
			}
			if (flag!=line.cmdc) {
				dup2(pipegroup[flag-1][1],STDOUT_FILENO);
			}
			if (line.cmdc>1)
				for (int i=0;i<line.cmdc-1;i++){
					close(pipegroup[i][0]);
					close(pipegroup[i][1]);
				}
			if (line.commands[flag-1].irdr){
				int fin = open(line.commands[flag-1].irdr,O_RDWR,0666);
				dup2(fin,STDIN_FILENO);
				close(fin);
			}
			if (line.commands[flag-1].ordr){
				int fout;
				if (line.commands[flag-1].append_o==0) fout = open(line.commands[flag-1].ordr,O_RDWR|O_CREAT|O_TRUNC,0666);
				else fout = open(line.commands[flag-1].ordr,O_RDWR|O_CREAT|O_APPEND,0666);
				dup2(fout,STDOUT_FILENO);
				close(fout);
			}
			break;
		}

	}
	if (flag==0) {
		for (int i=0;i<line.cmdc-1;i++){
				close(pipegroup[i][0]);
				close(pipegroup[i][1]);
		}
		waitpid(pid[line.cmdc-1],NULL,0);
		free(pid);
		for (int i=0;i<line.cmdc-1;i++) free(pipegroup[i]);
		if (line.cmdc>1) free(pipegroup);
		cmdl_clean(line);
		exit(0);
	}
	else{
		char dir[] = "/bin/";
		strcpy(dir,line.commands[flag-1].argv[0]);
		execvp(dir,line.commands[flag-1].argv);
	}
	exit(0);
}
