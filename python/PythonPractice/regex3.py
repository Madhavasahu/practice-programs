#! /usr/bin/python3
import re
strg = "8106103191464564691-81061031984asdf91-9849258002dasfasdf23433333391-899w91-8309923351ewrr234"
regex = re.compile(r'(91)?-?(\d{10})') #match the numbers starting with optional area code pattern i.e '91-'.
matchObj = regex.search(strg) #returns None if nothing matched. so first check for it to be none
if matchObj is not None:
    print(matchObj.group()) # same as matchObj.group(0)
    print(matchObj.groups()) # returns all the matched group in the found match
    print(matchObj.group(0)) #same as matchObj.group()
    print("area code is {}".format(matchObj.group(1)))
    print("phone number is {}".format(matchObj.group(2)))
findObj = regex.findall(strg) #list of tuples each tuple having all the groups
print(findObj)
