#!/bin/bash

printf "123\n234\n345\n" | cat > "in.txt"
strace -e openat -P "out.txt" -e fault=openat:error=EDQUOT ./move "in.txt" "out.txt" > /dev/null 2> /dev/null

if [ $? -ne 3 ]; then
	echo "ERROR"
else
	echo "OK"
fi

