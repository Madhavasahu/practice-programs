#!/bin/bash
var=10
while [ $var -le 10 ]
do
	echo $var
	var=$[ $var - 1 ]
done

