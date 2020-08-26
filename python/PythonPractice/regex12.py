#! /usr/bin/python3

import re
with open('sampleData.txt','r') as fHandle:
    srcStr = fHandle.read()
spaceRegex = re.compile(r'\s+|\n')
srcStr = spaceRegex.sub("",srcStr) #to remove single or multiple spaces
#srcStr = spaceRegex.sub(" ",srcStr) #to replace multiple spaces with single spaces
print(srcStr)
print('\n\n')
phoneRegex = re.compile(r'''
(\d\d\d-\d\d\d-\d\d\d\d) # for phone numbers like 412-565-9978 
''',
re.VERBOSE)

print(re.findall(phoneRegex,srcStr))

EmailRegex = re.compile(r'''
[a-z0-9.%+-]+ #for user name
@             #for @ symbol
[a-z0-9.%+-]+ #for domain name
\.
\w{,3}
''',re.VERBOSE|re.I)

print(re.findall(EmailRegex,srcStr))
