import re
strg = "8106103191madhava jagannadh sahu mat hat sat+91-9849258002 +11-9849258002 +89-1234567890 sadfdfs+91-8302223351"
regex = re.compile(r'(\+91)-(\d{10})')
mo = regex.search(strg) #returns only the first match
if mo is not None:
    print(mo.group(0))  #returns the combined result of groups matched, same as mo.group()
    print(mo.groups())  #return a touple of all matched groups
retList = regex.findall(strg) #returns all the matches strings in a list
if retList is not None:
    print(retList)
