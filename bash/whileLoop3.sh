#!/bin/sh
NAME=unknown
while [ "$INPUT" != "madhava" ]
do
    echo "Enter your name"
    read INPUT #do not use $INPUT here
    echo "You are ${INPUT}"
done
