import os

def find(name, path):
    for root, dirs, files in os.walk(path):
        if name in files:
            return os.path.join(root, name)
        
if not os.path.exists(r"D:\ubuntu\practice-programs\python\xilinxPython\temp"):
    os.system("mkdir temp")
    os.chdir("temp")
    print("cloning git repo")
    os.system("git clone https://github.com/Madhavasahu/practice-programs.git")
filePath = find("data.txt",r"D:\ubuntu\practice-programs\python\xilinxPython")
nums,alphs = [], []
with open(filePath,"r") as fHandle:
    for line in fHandle:
        alphs.append(line.strip().split(":")[0])
        nums.append(int(line.strip().split(":")[1]))
uniqueKeys = list(dict.fromkeys(alphs))
for i in range(len(uniqueKeys)):
    tempList = []
    for j in range(len(alphs)):
        if uniqueKeys[i] == alphs[j]:
            tempList.append(nums[j])
    print("key: {}, min value: {}, max value: {}".format(uniqueKeys[i],min(tempList),max(tempList)))