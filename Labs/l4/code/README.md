# Lab 4 Code
+ Zhang Yichi 516370910260

## Introduction

It is the directory for the code of lab 4, which requires to build two program to read and sort data from files using linked lists. And libraries need to be built and linked in compiling.

## Instruction on Compiling and Running
Following steps can be a reference of compiling this code.

1. Make a directory named "build" and get into it.
2. Run 
```
cmake build ..
make
```
in the directory, then there are 4 executables created. cli and cli_s are for command line interface, and user/user_d are for user interface. cli_s and user_d are compiled with dtatic and dynamic libraries linking respecitvely.

## File Manifest
### list.c/.h
The two are for the implementation of linked lists
### api.c/.h
The two are for the implementation for specific operations in this lab. api.h is just based on the given code in the lab description
### interface.c/.h
The two are for the interface dispatch functions
### user.c/cli.c
These two are main funcitons for the two different programs
### rand_int.txt
This contains a test case for the two programs
### CMakeLists.txt
It is for compling using Cmake