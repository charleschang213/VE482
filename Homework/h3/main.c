#include "ex3_ll.h"
#include "ex3_sorter.h"
#include <stdlib.h>
#include <time.h>
int main(int argc,char *argv[]){
    srand(time(NULL));
	if (argc!=3) printf("Incorrect arguments\n");
	else sorter(argv);
    return 0;
}
