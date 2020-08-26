#! /usr/bin/python3

import re
stg = "my name is Madhava and I am an agent like you and want to meet u at I41"
regex1 = re.compile(r'\w\d+')
regex2 = re.compile(r'Madhava')
#findings = regex1.findall(stg)
#findings2 = regex2.findall(stg)
enc = regex1.sub('xxxx', stg) #substitute the xxx string with the found match in stg source str
enc2 = regex2.sub('xxxx', enc)
print(enc2) #here source string stg is not changed in place
