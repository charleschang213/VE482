# Project2 Instruction  
## To-do List
0. Task Distribution for Task 1
1. Implement all management/data queries

## Task 0: Task Distribution for Task 1
1. The task 1 goals have been listed on main.cpp
2. If you want to do one of these, put your name with a bracketsd
3. There are 12 goals so 3 per 1 person is reasonable
## Task 1: Query Implementation
### Management Query
1. Go to ./query/management and create xxxQuery.cpp/.h ("xxxQuery" is the ./query/QueryBuilders.cpp:line49,line61 inside <>)
2. Implement them, using other files in management as reference
3. Comment the line calling NopQuery and decomment the next line calling true query in QueryBuilders.cpp
4. Add the two files into Cmakelists.txt
5. Compile and test it
6. If it runs well, delete the term in TODO in main.cpp and push it to the server

### Data Query
1. Go to ./query/data and create xxxQuery.cpp/.h ("xxxQuery" is in  ./query/QueryBuilders.cpp:line155-192(those commented lines) inside <>)
2. Implement them, using other files in data as reference
3. Comment the line calling NopQuery and decomment the next line calling true query in QueryBuilders.cpp
4. Add the two files into Cmakelists.txt
5. Compile and test it
6. If it runs well, delete the term in TODO in main.cpp and push it to the server

## Test Tips
+ Some extra queries have been implemented such as List table, Print table can be used to see result when the program is running

## Reminder  
+ Do not submit a version that cannot compile successfully onto server