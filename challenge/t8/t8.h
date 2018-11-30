#ifndef CHALLENGE_T8_H
#define CHALLENGE_T8_H
#include <linux/ioctl.h>
#define T8_MAGIC 'f'
#define T8_READ _IOR(T8_MAGIC,1,char*)
#define T8_WRITE _IOW(T8_MAGIC,2,char*)
#endif
