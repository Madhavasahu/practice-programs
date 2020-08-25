#!/bin/bash
read -p "Enter y or n" RESPONSE
case "$RESPONSE" in
    [yY]|[yY][eE][sS])
        echo "You answered yes";;
    [nN]|[nN][oO])
        echo "You answered no";;
    *)
        echo "Invalid answer";;
esac
