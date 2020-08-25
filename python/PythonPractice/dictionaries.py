sampleDict = {}  #creating a empty dictionary
print(sampleDict)
lis = ['a','b','c']
for i in [0,1,2]:
    sampleDict[i] = lis[i]
print(sampleDict)
for key,value in sampleDict.items():
    print(key,value)
list1 = list(sampleDict)  #when converting a dict to list, we will have list of dict's keys only
st = set(sampleDict)
newDict = {x:x*100 for x in range(4)} #dict comprehension
print(newDict)
print(st)  #prints a set with sampleDict keys as elements
print(list1)
sampleDict.setdefault(5,'madhava')
print(sampleDict)