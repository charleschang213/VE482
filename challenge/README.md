<img src="image/icon.jpg" align="right" height="130" width="130"/>  

# <br>VE482 Linux Challenge</br> ![Author](https://img.shields.io/badge/Author-Zhang%20Yichi-orange.svg) ![Progress](https://img.shields.io/badge/Progress-8%2F20-yellow.svg)<br></br>

## Platform  
In this challenge, all codes are compiled/tested in my Aliyun ECS server. The basic information is given below:
+ OS: Ubuntu 18.04 bionic
+ Kernel: x86_64 Linux 4.18.0-041800-generic  
## Introduction
This is the directory for Zhang Yichi's working on the Linux challenge for VE482 course. To access my work on a certain task, get into the corresponding task directory and you will see the source code. Also, for further explanations and test results, please refer to this README file.

## Task Manifest
### Task 1
The task asks to write a kernel module and use Makefile to compile it. The source code and Makefile are in the directory t1. In the Makefile, I use $(shell uname -r) to detect the version of the kernel.

To see the effect of unload the module, I also let it output "Good night ve482!" when exiting. The image below shows the result of compilation and testing.

<p style="text-align:center"><img src="image/t01_1.png" /></p>  

### Task 2  
I have already cloned the latest git tree of linux kernel by Linus Trovald. 

I use the directory /root/build/kernel to store the build result. The first step of compiling is set the confuguration of the version name. Use the command   

> make O=/root/build/kernel menuconfig

In the apeearing interface, tick the highlighten option to enable LOCALVERSION_AUTO.  

<p style="text-align:center"><img src="image/t02_1.png" /></p>

Then do the following

> make O=/root/build/kernel localmodconfig
> make O=/root/build/kernel  
> make O=/root/build/kernel modules_install   
> make O=/root/build/kernel install  

Then the kernel image and system map will appear in the directory /boot/. Reboot the system and the kernel appears to be the new one.

<p style="text-align:center"><img src="image/t02_2.png" /></p>

### Task 3
This is done by modifying the EXTRAVERSION field in Makefile. After rebuilding and reboot, the version string shows 

<p style="text-align:center"><img src="image/t03_1.png" /></p> 

The postfixes are due to my enabling of LOCALVERSION_AUTO, and "dirty" means the kernel is modified compared with the original version.

Next is do the patch. use the following commands  

> git add Makefile  
> git commit -s -v  
> git format-patch master  

The description of the patch is shown below  

<p style="text-align:center"><img src="image/t03_2.png" /></p>   

Then use the patch checking tool for to check 

<p style="text-align:center"><img src="image/t03_3.png" /></p> 

### Task 4  

I modified the code (The modified codes are in directory t4) and it shows that both the source code and the Makefile pass the check.

<p style="text-align:center"><img src="image/t04_1.png" /></p> 

### Task 5

Because I cannot plug USB into ECS, the base I used is the dual OS on my computer, which is of Archlinux with Linux kernel 4.19.2

The main point is to write a interface driver for usb keyboard devices. The result is shown below

<p style="text-align:center"><img src="image/t05_1.png" /></p> 

The first line shows that the new driver is registered, and following lines happened when I plugged my USB keyboard. It seems that the new module works. The codes are in directory t5

### Task 6  

The basic usage of misc device is used in this part. When loading the module and deleting the module, it can be seen in the following result that the device will appear and disappear as well.  

<p style="text-align:center"><img src="image/t06_1.png" /></p> 

And I wrote a test program to see its performance. The program will do 1. Read 2. Write correct value 3. Write invalid value to the device and the output is seen below.

<p style="text-align:center"><img src="image/t06_2.png" /></p> 

It can be seen that the module works. The source code for the module and the test program is given in the directory t6

### Task 7

I have built the kernel and booted with it. It can be shown in the picture below that the kernel version is now 4.20.0-rc3-next-20181122

<p style="text-align:center"><img src="image/t07_1.png" /></p> 

### Task 8

The module is installed and the three files can be seen using ls command 

<p style="text-align:center"><img src="image/t08_1.png" /></p> 

In the test program, the "hobby" part is similar to that of task 7, and the jiffies part is also simple reading the file. In the info part, the program will first try to wirte the "generated number" into the file and read the data from it to "Line got". 

It can be easily seen that when the user is root, the write and read are processed normally. And when a non-root user is usin gthe program, the data read is still the data written by the root, which satisfies the requirements.

The source code for both kernel module and test program are in the t8 directory.

## Contact 
**Zhang Yichi**  

+ Email: [charleschang213@sjtu.edu.cn](mailto:charleschang213@sjtu.edu.cn)
+ Student ID: 516370910260