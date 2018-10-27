# VE482 h4 Programming Part
+ Zhang Yichi 516370910260

## Introduction  
This is the archive for codes for Ex.3 and Ex. 4 in VE482 h3. To see the result of the demo for the code, please open the directory in shell and type  
> ./ex3_1.sh & ./ex3_1.sh (Ex. 3 (1))
>
> ./ex3_2.sh & ./ex3_2.sh (Ex. 3 (2))

for Ex. 3. For Ex. 4, you need to compile ex4.c and run 

## Program Manifest
### Ex.3 
This question requires two shell scripts which generate a file with incrementing lines---one with race condition and one without. For the first script ex3_1.sh, what I see is the numbers begin to duplicate from 150, which means that the race condition appears when the 75th iteration comes. And in part 2 there is no such problem

### Ex.4
This question asks to implement a semaphore in the given program. The header file semaphore.h is used and functions such as sem_init, sem_wait, sem_post are used. Also ,the threads are created based on semaphore argument.