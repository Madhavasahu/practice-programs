import os

def find(name, path):
    for root, dirs, files in os.walk(path):
        if name in files:
            return os.path.join(root, name)
def main():
    bigList = []
    keySet = set()
    finalKeySet = set()
    valueSet = set()
    if not os.path.exists(r"D:\ubuntu\practice-programs\python\xilinxPython\temp"):
        os.system("mkdir temp")
        os.chdir("temp")
        print("cloning git repo")
        os.system("git clone https://github.com/Madhavasahu/practice-programs.git")
    path = find("data.txt",r"D:\ubuntu\practice-programs\python\xilinxPython")
    with open(path,"r") as fHandle:
        for line in fHandle:
            bigList.append(line.strip().split(":"))
        for i in range(len(bigList)):
            if (bigList[i][0] in finalKeySet):
                continue
            for j in range(i, len(bigList)):
                if bigList[i][0] == bigList[j][0]:
                    keySet.add(bigList[j][0])
                    valueSet.add(int(bigList[j][1]))
                    finalKeySet.add(bigList[j][0])
            if keySet:
                tempList1 = list(keySet)
                print("variable: {}, min is {}, max is {}".format(tempList1[0], min(valueSet), max(valueSet)))
            keySet.clear()
            valueSet.clear()

if __name__ == "__main__":
    main()