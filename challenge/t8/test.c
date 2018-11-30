#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <string.h>
#include "t8.h"
#include <time.h>
int main(){
	srand(time(NULL));
	int fd = open("/sys/kernel/debug/ve482hobby/hobby",O_RDWR);
	int fd2 = open("/sys/kernel/debug/ve482hobby/jiffies",O_RDONLY);
	int fd3 = open("/sys/kernel/debug/ve482hobby/info",O_RDWR);
	int ret = 0;
	char *getdata = malloc(100*sizeof(char));
	char *data1 = malloc(100*sizeof(char));
	char *data2 = malloc(100*sizeof(char));
	char *data3 = malloc(100*sizeof(char));
	char *data4 = malloc(100*sizeof(char));
	char *data5 = malloc(100*sizeof(char));
	memcpy(data1,"ve482hobby!",11);
	memcpy(data2,"abcdefg",7);
	ret = ioctl(fd,T8_READ,getdata);
	ret = ioctl(fd,T8_WRITE,data1);
	ret = ioctl(fd,T8_WRITE,data2);
	ret = ioctl(fd2,T8_READ,data3);
	printf("---hobby part---\n");
	printf("%s\n",getdata);
	printf("%s\n",data1);
	printf("%s\n",data2);
	printf("---jiffies part---\n");
	printf("%s\n",data3);
	printf("---info part---\n");
	sprintf(data4,"%d",rand());
	printf("Number generated: %s\n",data4);
	ret = ioctl(fd3,T8_WRITE,data4);
	ret = ioctl(fd3,T8_READ,data5);
	printf("Line got: %s\n",data5);
	free(getdata);
	free(data1);
	free(data2);
	free(data3);
	free(data4);
	free(data5);
	close(fd);
	close(fd2);
	close(fd3);
	return 0;
}
