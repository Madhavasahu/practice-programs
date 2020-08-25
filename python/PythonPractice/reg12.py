#! /usr/bin/python3

import re
stg = "Agent Alice gave the documents to Agent Bob"
regex = re.compile(r'Agent (\w)(\w*)') #to get the A in Alice and B in Bob
print(regex.findall(stg))
resu = regex.sub(r'Agent \1***',stg) #replace the first group in the source string
print(resu) #here, the \1 represent first group which is A,B and \2 represent second group