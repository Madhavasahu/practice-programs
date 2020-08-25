#!/bin/bash
file="for.sh"
if [ -e $file ];then
    echo "$file exist"
else
    echo "$file doesn't exist"
fi
