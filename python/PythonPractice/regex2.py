import re
with open("data.txt","r") as fHandle:
    line = fHandle.read()
print(line)
regex = re.compile(r'data:[0-9]+')
lis = regex.findall(line)
print(lis)
templist = []
for element in lis:
    templist.append(int(element.split(':')[1]))
print('average {}'.format(sum(templist)/len(templist)))
