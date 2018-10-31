# Project2 Instruction  
## To-do List
1. Implement all management/data queries

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
+ There is a very very small testcase .tbl file (just same as the example in p2.pdf) in build
+ Normal git server submit process:
  1. get into your own branch(for the first time, use git checkout -b xxx to create and afterwards just use git checkout xxx)
  2. Do modifications, add and commit
  3. get a copy from server using git pull origin master
  4. (if not appear in step 3) merge master use git merge master
  5. push using git push origin xxx:master 