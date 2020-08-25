#!/bin/bash
for dir in $(ls -1)
do
	echo "$dir"
done >> result.txt
