#! /usr/bin/python3
# ? is used in regular expression for detecting optional characters
# here in below we can find the numbers which may or may not have area code 
import re
strg = "46456464asdf91-31-9849258002dasfasdf23433333391-899w8309923351ewrr234"
regex = re.compile(r'(\d\d-)?(\d{10})')  #to detect numbers with optional area code
mo = regex.search(strg)
lis = regex.findall(strg)
print(lis)
if not mo is None:
    print(mo.groups())