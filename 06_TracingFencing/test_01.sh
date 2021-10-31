#!/bin/bash

printf "123\n234\n345\n" | cat > "in.txt"
strace -e openat -P "in.txt" -e fault=openat:error=EACCES ./move "in.txt" "out.txt" > /dev/null 2> /dev/null

if [ $? -ne 2 ]; then
	echo "ERROR"
else
	echo "OK"
fi

