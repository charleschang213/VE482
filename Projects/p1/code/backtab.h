#ifndef BACKTAB_H
#define BACKTAB_H
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
typedef struct _background_{
	pid_t pid;
	char *command;
}background;

typedef struct _backtab_{
	int num;
	background *arr;
}backtab;

void bt_init(backtab *bt);
void bt_clean(backtab *bt);
void bt_append(backtab *bt,pid_t p,char *c);
void bt_show(backtab *bt);
#endif
