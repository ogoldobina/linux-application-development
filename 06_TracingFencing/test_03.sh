#!/bin/bash

printf "123\n234\n345\n" | cat > "in.txt"
strace -e read -P "in.txt" -e fault=read:error=EIO ./move "in.txt" "out.txt" > /dev/null 2> /dev/null

if [ $? -ne 4 ]; then
        echo "ERROR"
else
        echo "OK"
fi
