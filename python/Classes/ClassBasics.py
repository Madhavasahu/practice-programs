class Test:
    #variables defined above init method are class variables.
    remark = 'good' # This is not connected to any particular instance
    #We need to give some documentation for the class like name is a string. So that user can be informed about the data type.
    def __init__(self,name,rollNo):
        self.name = name
        self.rollNo = rollNo
    #Operations/Actions--->Methods
    def printDetails(self,outVar=122):#We can provide outside variables also
        print("My name is {}".format(self.name))
        print("My rollno is {}".format(self.rollNo))
        print("Variable from outside is {}".format(outVar)) #outVar variable is not connected to any instance
def main():
    test = Test(name = "Madhava",rollNo = 36)
    test.printDetails(465465) #We can call this without any parameter to take the already given default value
    print("Remark is %s "% Test.remark) #We call class variable with Class name
    
if __name__ == "__main__":
    main()
