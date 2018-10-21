# VE482 h3 Programming Part
+ Zhang Yichi 516370910260

## Introduction  
This is the archive for codes for Ex.3 in VE482 h3. To see the result of the demo for the code, please open the directory in shell and type  
> ./test.sh

Sometimes a chmod command that authorize the permision of execution might be needed. The script test.sh will compile and run the program.  

## Program Manifest
### Ex.3 
This question requires an implementation of a linked list which fits multiple data types. Now three different data types are implemented: int,double and string(char* in C). And another things is to parse a file and output the result of sorting based on three different sorting types.

The file ex3_ll.c/.h defines the linked list data types and several functions. The void pointer value is used to store unknmown type of data. Fucntion pointers are applied to call different functions for different data types. 

Descending sorting will be finished in the meantime of appending new elements. Because the linked list is a double linked list, printing the list reversely will finish the inc part. The algorithm for rand is randomly remove a node from the list and print it, and repeat this process until the list is empty.

The file ex3_sorter.c/.h defines the specific parser for the file and main.c gives the main function which runs the test. The test will be performed based on the file rand_int.txt