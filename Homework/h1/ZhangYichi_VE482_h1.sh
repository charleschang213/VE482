
# !/bin/bash
# Create new user
useradd -m charles

# List all running process
ps -a

# Display the CPU and Memory condition
top

# Redirect random output to two files
echo "VE482" > 1.txt
echo "Manuel Charlemagne" > 2.txt

# Concatenate the two previous files
cat 2.txt >> 1.txt

# View the result in hexdecimal values
hexdump 1.txt

# Finding files
find /usr/src -name '*semaphore*' | xargs grep 'ddekit_sem_down'
