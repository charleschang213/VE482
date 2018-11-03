# !/bin/bash
echo ****VE482 h3 Ex. 3 Test****
echo Making...
make
echo *******Original File*******
cat rand_int.txt
cp rand_int.txt backup.txt
echo Press Enter
read
echo Perform inc...
./ex3_sorter rand_int.txt inc
echo ********Result File********
cat inc_int.txt
echo Press Enter
read
echo Perform dec...
./ex3_sorter rand_int.txt dec
echo ********Result File********
cat dec_int.txt
echo Press Enter
read
echo Perform rand...
./ex3_sorter rand_int.txt rand
echo ********Result File********
cat rand_int.txt
mv backup.txt rand_int.txt

