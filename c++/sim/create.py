#!/usr/bin/python3

import os
import sys

def createFile(newFile):
    fptr = open(newFile,"w")
    fptr.write("""#include<iostream>
using namespace std;\nint main(int argc, char* argv[]){\n\n\n\n\treturn 0;\n}""")
    fptr.close()

def main():
    if len(sys.argv) < 2:
        print("usage: file name")
    else:
        newFile = sys.argv[1]
        #print("given file is {}".format(newFile))
        createFile(newFile)

if __name__ == "__main__":
    main()
