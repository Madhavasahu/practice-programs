#!/bin/bash
echo -e "enter directory to test\n"
read directory
if [ -d $directory ];then
	echo -e "directory exist"
else
	echo -e "not here"
fi
