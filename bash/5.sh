#!/bin/bash
echo -e "Welcome to my Script\n"
echo -e "talk to me...!"
while :
do 
	read str
	case $str in 
		hi)
			echo "hello...." ;;
		bye)
			echo "ok..bye!!" 
			break;;
		*)
			echo "sorry i didnt get it";;
	esac
done

