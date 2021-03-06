class A(object):
    def __init__(self,name,age,salary):
        self.__name = name
        self.__age = age
        self.__salary = salary
    def getReport(self):    
        return [self.__name,self.__age,self.__salary]
    def setReport(self,name,age,salary):
        self.__name = name
        self.__age = age
        self.__salary = salary
    def printReport(self):
        raise NotImplementedError("couldn't make a call to printReport")
    def printAge(self):
        print(self.__age)
    def setAge(self,age):
        self.__age=age
class B(A):
    def __init__(self, *args):
        A.__init__(self, *args)
    def printReport(self):
        print("printing report :",end="")
        print(super().getReport())   

def main():
    a=A("asfdas",322,3232323)
    a.setAge(65)
    b=B("asdfasddd",23,232323)
    b.printAge()
    a.printAge()
if __name__ == "__main__":
    main()