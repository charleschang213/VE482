#include "backtab.h"
void bt_init(backtab *bt){
	bt->num = 0;
	bt->arr = NULL;
}
void bt_clean(backtab *bt){
	for (int i=0;i<bt->num;i++) free(bt->arr[i].command);
	if (bt->num!=0) free(bt->arr);
}

void bt_append(backtab *bt,pid_t p,char *c){
	bt->num++;
	if (bt->num==1) bt->arr = malloc(sizeof(background));
	else bt->arr = realloc(bt->arr,bt->num*sizeof(background));
	bt->arr[bt->num-1].pid = p;
	bt->arr[bt->num-1].command = malloc((strlen(c)+1)*sizeof(char));
	strcpy(bt->arr[bt->num-1].command,c);
}
void bt_show(backtab *bt){
	for (int i=0;i<bt->num;i++){
		printf("[%d] ",i+1);
		//if ((waitpid(bt->arr[i].pid,NULL,WNOHANG)==-1)&&(errno==ECHILD)) printf("done ");
		//else printf("running ");
		if (waitpid(bt->arr[i].pid,NULL,WNOHANG)==0) printf("running ");
		else printf("done ");
		printf("%s\n",bt->arr[i].command);
	}
}
