#!/bin/bash
: 'for COLOR in red blue gree white
do
    echo "color is $COLOR"
done'
: 'printf "Enter your name\n"
read name
echo "Hello $name"
printf "\n"
files=$(ls)
for file in $files
do
    echo $file
done'
scripts=$(ls *.sh)
number=1
for script in $scripts
do
    printf "renaming $script to $number"
    mv $script $number
    $((number=number+1))
done
