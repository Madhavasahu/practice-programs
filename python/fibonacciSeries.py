#! /usr/bin/python3 

# 0 1 1 2 3 5
import sys
counter = 0
summ = 0
a = 0
b = 1
n = int(input("enter the uppter limit"))
if (n<0):
    print('invalid input')
    sys.exit()
while(counter < n):
    if counter == 0:
        summ = 0
    else:
        a = b 
        b = summ
        summ = a+b
    counter += 1
    print(summ)
