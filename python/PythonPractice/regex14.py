#! /usr/bin/python3 
import re
stg ="""Ross McFluff: 834.345.1254 155 Elm Street
Ronald Heathmore: 892.345.3428 436 Finley Avenue
Frank Burger: 925.541.7625 662 South Dogwood Way
Heather Albrecht: 548.326.4584 919 Park Place"""
retList = re.split(r'\n+',stg)
print(retList)
for entry in retList:
    print(re.split(r':? ',entry)) # r':? ' is a regex pattern need to know
