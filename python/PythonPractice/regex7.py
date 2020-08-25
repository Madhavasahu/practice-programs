#! /usr/bin/python3

import re
stg = "as      fdasdfasmadhava;lk234234l;jkk;lsdfaslkdfjasldkfj23423;lj;jsdfjsdf:asdfsdf65465464sad_0"
regex = re.compile(r'\w+') #for detecting words.
#if the string has characters other than alphanumericals, underscore(_) (such as , : ; space etc) it treats them
#as seperators 
mo = regex.search(stg)
print(mo.group())
lis = regex.findall(stg)
print(lis)
