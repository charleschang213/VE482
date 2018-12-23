# VE482 h5 Programming Part ![ZhangYichi](https://img.shields.io/badge/author-Zhang%20Yichi-blue.svg)
## Introduction
This is the directory storing Zhang Yichi's programming homework for VE482 h5. There is only one file ex3.c for the Exercise 3

## Instruction
To compile and run, please use command  

> $ gcc -o ex3 ex3.c  
> $ ./ex3

## File Manifest

### ex3.c
It implements the Banker's algorithm in the function banker(). And there is also a demo in the main function. It is a very simple case when every process holds 1 resource per each kind and request 1 more for each kind.

### Possible Improvement
I think now the data structure for the function's arguments(int **) are difficult to initialize a value. Maybe the data structure needs to be improved or maybe it can be implemented in C++ using STL containers.