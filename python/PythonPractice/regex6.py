#! /usr/bin/python3

import re
stg = "Batmobile is Batwowowoman things in pasadena, may be Batman is also there with Batwoman"
#regex = re.compile(r'(Bat(wo)+man)') # + is used to match atleast one match 
#regex = re.compile(r'(Bat(wo)*man)') # * is used to match zero or more than one match
regex = re.compile(r'(Bat(wo)?man)') # ? is used to match optional match i.e here 'wo' is optional 
mo = regex.search(stg)
if not mo is None:
    print(mo.groups())
retList = regex.findall(stg)
print(retList)