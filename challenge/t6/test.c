#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <string.h>
#include "t6.h"

int main(){
	int fd = open("/dev/hobby",O_RDWR);
	int ret = 0;
	char *getdata = malloc(100*sizeof(char));
	char *data1 = malloc(100*sizeof(char));
	char *data2 = malloc(100*sizeof(char));
	memcpy(data1,"ve482hobby!",11);
	memcpy(data2,"abcdefg",7);
	ret = ioctl(fd,T6_READ,getdata);
	ret = ioctl(fd,T6_WRITE,data1);
	ret = ioctl(fd,T6_WRITE,data2);
	printf("%s\n",getdata);
	printf("%s\n",data1);
	printf("%s\n",data2);
	free(getdata);
	free(data1);
	free(data2);
	return 0;
}
