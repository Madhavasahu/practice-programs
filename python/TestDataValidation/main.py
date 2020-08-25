def main():
    lastStreamID = 0
    lineList = []
    lineNumber = 0
    try:
        with open("TestData.txt","r") as fHandle:
            for line in fHandle:
                lineNumber += 1
                line = line.strip()
                if not line:
                    continue
                if not line.startswith("DATAI",0):
                    continue
                else:
                    currentstreamID = int(line.strip("DATAI: ")[0:4],16)
                    if lineNumber == 1:
                        lastStreamID = currentstreamID
                        continue 
                    difference = currentstreamID - lastStreamID
                    lastStreamID = currentstreamID
                    if difference > 1 or difference < 1:
                        print("Invalid line : "+str(lineNumber)+" and "+"Data: "+line)
                        lineList.append(lineNumber)
        print("\nTotal number of invalid lines: {}".format(len(lineList)))
    except:
        print("operation failed\n")
        
if __name__ =="__main__":
    main()