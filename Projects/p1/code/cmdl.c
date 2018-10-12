/*************************************************************************
    > File Name: cmdl.c
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-09-16 19:54:25
 ************************************************************************/

#include "cmdl.h"

cmdl parse(char* str,char** quotelist){
	int quoteflag = -1;
	char* ttmp = malloc((strlen(str)+1)*sizeof(char));
	strcpy(ttmp,str);
	cmdl newline;
	char **command_group;
	newline.cmdc = 0;
	newline.commands=NULL;
	newline.indup = newline.outdup = 0;
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
			char *innerend;
			char *inr = strstr(tmp,"<");
			char *outr = strstr(tmp,">");
			if (inr) *inr=0;
			if (outr) *outr=0;
			if ((tmp!=inr)&&(tmp!=outr)){
				int quotemode = 0;
				if (tmp[0]=='\''){
					innerend = strstr(tmp+1,"\'");
					if (!innerend) {
						inr = outr = NULL;
						quotemode = 1;
					}
					quoteflag++;
					tmp = quotelist[quoteflag];
				}
				else if (tmp[0]=='\"'){
					innerend = strstr(tmp+1,"\"");
					if (!innerend){
						inr = outr = NULL;
						quotemode = 2;
					}
					quoteflag++;
					tmp = quotelist[quoteflag];
				}
				newline.commands[i].argc++;
				newline.commands[i].argv = realloc(newline.commands[i].argv,newline.commands[i].argc*sizeof(char*));
				newline.commands[i].argv[newline.commands[i].argc-1]=malloc((strlen(tmp)+1)*sizeof(char));
				strcpy(newline.commands[i].argv[newline.commands[i].argc-1],tmp);
				if (quotemode==1){
					tmp = strtok(NULL,"\'");
				}
				else if (quotemode==2){
					tmp = strtok(NULL,"\"");
				}
			}
			if (inr){
				if ((newline.commands[i].irdr)||(i!=0)){
					newline.indup = 1;
					for (int i=0;i<newline.cmdc;i++) free(command_group[i]);
					free(command_group);
					free(ttmp);
					return newline;
				}
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
				if ((newline.commands[i].ordr)||(i!=newline.cmdc-1)){
					newline.outdup = 1;
					for (int i=0;i<newline.cmdc;i++) free(command_group[i]);
					free(command_group);
					free(ttmp);
					return newline;
				}
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

void exec_cmdl(cmdl line,int backmode,int num,char *command,int *fd3){
	if (line.cmdc==0) return;
	if (line.commands[0].irdr){
			int fin = open(line.commands[0].irdr,O_RDWR,0666);
			if (fin==-1){
				printf("%s: No such file or directory\n",line.commands[0].irdr);
				fflush(stdout);
				exit(0);
			}
			close(fin);
	}
	if (line.commands[line.cmdc-1].ordr){
			int fout;
			if (line.commands[line.cmdc-1].append_o==0) fout = open(line.commands[line.cmdc-1].ordr,O_RDWR|O_CREAT|O_TRUNC,0666);
			else fout = open(line.commands[line.cmdc-1].ordr,O_RDWR|O_CREAT|O_APPEND,0666);
			if (fout==-1){
				printf("%s: Permission denied\n",line.commands[line.cmdc-1].ordr);
				fflush(stdout);
				exit(0);
			}
			close(fout);
	}

	if (backmode==1) {
		printf("[%d] ",num+1);
		printf("%s\n",command);
		write(fd3[1],&num,4);
		close(fd3[1]);
	}
	else close(fd3[1]);
	fflush(stdout);
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
		for (int xx=0;xx<line.cmdc;xx++) {
			int rv;
			waitpid(pid[xx],&rv,0);
			if (rv==256){
				printf("%s: command not found\n",line.commands[xx].argv[0]);
			}
		}
		free(pid);
		for (int i=0;i<line.cmdc-1;i++) free(pipegroup[i]);
		if (line.cmdc>1) free(pipegroup);
		cmdl_clean(line);
		setbuf(stdin,NULL);
		exit(0);
	}
	else{
		if (strcmp(line.commands[flag-1].argv[0],"pwd")==0){
			printf("%s\n",pwd());
			exit(0);
		}
		if (strcmp(line.commands[flag-1].argv[0],"cd")==0){
			cd(line.commands[flag-1].argv[1]);
			exit(0);
		}
		char dir[100]={0};
		strcpy(dir,"/bin/");
	    strcpy(dir,line.commands[flag-1].argv[0]);
		execvp(dir,line.commands[flag-1].argv);
		exit(1);
	}
	exit(0);
}
