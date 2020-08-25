from builtins import staticmethod
class Test(object):
    def __init__(self,number):
        self.number = number
    def __str__(self):
        return "{}".format(self.number) #should only return strings only
    @classmethod
    def createTest(cls,number):  #used in factory method and returns object same as __init__
        number = number +5          #called on classname (classname.methodaname(args))
        return cls(number)
    @staticmethod
    def randomMethod(number):  #used as utility function and doesn't return any object. it is a just like function
                                #called on class name (classname.methodname(args))
        return number +10
    def getNumber(self):
        return self.number
    
def main():
    test1 = Test(5)
    print(test1)
    test2 = Test.createTest(5)
    print(test2.getNumber())
    print(test2)
    test3 = Test.randomMethod(5)
    print(test3)
    
if __name__ == "__main__":
    main()