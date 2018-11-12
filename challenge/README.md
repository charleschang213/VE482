<img src="image/icon.jpg" align="right" height="130" width="130"/>  

# <br>VE482 Linux Challenge</br> ![Author](https://img.shields.io/badge/Author-Zhang%20Yichi-orange.svg) ![Progress](https://img.shields.io/badge/Progress-1%2F20-yellow.svg)<br></br>

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

## Contact 
**Zhang Yichi**  

+ Email: [charleschang213@sjtu.edu.cn](mailto:charleschang213@sjtu.edu.cn)
+ Student ID: 516370910260