#!/bin/sh
printf "What is your name\n"
read NAME
if [ -z "$NAME" ];then
    NAME=`whoami`
fi
echo "Hello $NAME"
