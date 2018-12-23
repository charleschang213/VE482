# !/bin/bash i
if [ ! -f "ex3_file.txt" ]; then
	echo 0 > ex3_file.txt
fi
for ((i=0;i<100;++i)); do
	(
	 	flock 9
		last=$(tail -1 ex3_file.txt)
		last=$[last+1]
		echo $last >> ex3_file.txt
	) 9<>ex3_file.txt
done
