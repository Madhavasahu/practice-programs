#! /usr/bin/python3

import re
stg = "madahva\nsahu\nsadfasd;fasdfa\n"
regex = re.compile(r'\w{5}') #to get everything except space and newline
lis = regex.findall(stg)
print(lis)
