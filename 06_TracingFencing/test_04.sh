#!/bin/bash

printf "123\n234\n345\n" | cat > "PROTECTED_in.txt"
LD_PRELOAD=./my_remove.so ./move PROTECTED_in.txt out.txt  > /dev/null 2> /dev/null
if cmp PROTECTED_in.txt out.txt;
    then echo "OK";
else echo "ERROR";
fi;
