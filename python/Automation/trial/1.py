import re
my_str = "\@ghhhhhhhhabc "
if(re.match(r'^\\[A-Za-z0-9]\s',my_str)):
    print("matcyhed")
else:
    print("not matched")
