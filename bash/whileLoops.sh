#!/bin/bash
number=0
while [ $number -ne 10 ]
do
    #number=$(($number+1))
    ((number++))
    printf "$number\n"
done
