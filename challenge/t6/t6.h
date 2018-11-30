#ifndef CHALLENGE_T6_H
#define CHALLENGE_T6_H
#include <linux/ioctl.h>
#define T6_MAGIC 'f'
#define T6_READ _IOR(T6_MAGIC,1,char*)
#define T6_WRITE _IOW(T6_MAGIC,2,char*)
#endif
