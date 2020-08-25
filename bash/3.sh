#!/bin/bash
echo -n "enter a and b values:"
read a b
if [ $a -eq $b ];then
	echo -e "they are equal\n"
else
	echo -e "they are not equal\n"
fi
user=madhava
echo -n "enter your name:"
read usr
if [ $usr = $user ];then
	echo -e "hello $usr"
else
	echo -e "i dont know you\n"
fi
