#! /usr/bin/python3

import re
stg = "Batmobile is a things in pasadena, may be Batman is also there with Batwoman"
regex = re.compile(r'Bat(mobile|man|woman)') # pipe is used to match one of possible groups
mo = regex.search(stg)
if not mo is None:
    print(mo.groups())
retList = regex.findall(stg)
print(retList)