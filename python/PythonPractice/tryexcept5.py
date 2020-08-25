class MyException(Exception):
    """
    Base class for user defined exceptions of the current module 
    """
    pass
class InputError(MyException):
    """
    exception class for input errors inherited from MyException
    
    Attributes:
    error no -- number showing the error for reference
    msg      -- explanation of the error in string format
    """
    def __init__(self, errorno, msg):
        self.errorno = errorno
        self.msg = msg
    def __str__(self):
        return "error msg: "+self.msg+", error no: "+str(self.errorno)
class DivisionError(MyException):
    """
    exception class for zero division errors inherited from MyException
    
    Attributes:
    msg      -- explanation of the error in string format
    """
    def __init__(self, msg):
        self.msg = msg
        
try:
    raise InputError(4,"please enter valid inputs")
except InputError as e:
    print(e)  #prints the instance variables values without __str__() function overidden
    print(e.msg)   #selective print
    print(e) #prints in the way want it to print defined in __str__() function
else:       # will get executed if everything is right
    print("success")
finally: #executes, whether or not a exception arises
    print("printing from finally!")
        