#! /usr/bin/python3 
import re
count = 0
with open("sampleString.txt") as fHandle:
    for line in fHandle: 
        count += 1
        regexObj = re.compile(r'\d+\.\d+')
        matchObj = regexObj.search(line)
        if matchObj:
            print("Found "+matchObj.group()+" at line number "+str(count))
