#include "funcs.h"
const char* pwd(){
	static char dir[200] = {0};
	getcwd(dir,200);
	return dir;
}

void cd(const char *dir){
	int result = chdir(dir);
	printf("%d\n",result);
}
