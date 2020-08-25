#!/bin/bash
echo -n "enter the values of a and b:"
read a b
if [ $a -eq 10 ] || [ $b -eq 100 ];then
	echo "true"
else
	echo "false"
fi
