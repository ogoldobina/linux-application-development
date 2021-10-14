#!/bin/bash

t=${1:-0.001}

coords=()
art=()

i=0
while IFS="" read -r line
do
    art+=("$line")
    for j in $(seq 0 $((${#line}-1)) )
    do
        coords+=("$i $j")
    done
    ((i=i+1))
done

tput clear
tput cup 0 0
for idx in $(shuf -i 0-$((${#coords[@]}-1)) )
do
    x=$(echo ${coords[$idx]} | cut -f 1 -d " ")
    y=$(echo ${coords[$idx]} | cut -f 2 -d " ")
    tput cup $x $y
    echo "${art[$x]:$y:1}"
    sleep $t
done
tput cup $i 0

