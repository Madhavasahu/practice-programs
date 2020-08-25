#!/bin/bash
function add()
{
sum=`expr $a + $b`
echo "Sum is :$sum";
}

echo "Enter the value of a";
read a
echo "Enter the valure of b";
read b
add
