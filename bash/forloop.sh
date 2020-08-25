#!/bin/bash
#IFS=internal field separator.it is defaultly 'space'. we can set it to space,tab or newline.here i am changing it temporarily to new line to print the lines.
IFS=$'\n'
j=1
file=test1.txt
for i in $(cat $file)
do	
	j=`expr $j + 1`
	echo "$i is $j line"
done
#same as above automatically detects new line
while read line
do
	echo $line
done < $file
