# A python program to create user-defined exception 

# class MyError is derived from super class Exception 
class MyError(Exception): 

    # Constructor or Initializer 
    def __init__(self, value, msg): 
        self.value = value 
        self.msg = msg
    # __str__ is to print() the value 
    
    def __str__(self):   #need to implement __str__ function to have our own printing format
                         #by default, without the __str__ function, printing a object, gives it instance variables
        return("error is "+self.msg+", error no: "+str(self.value)) 

try: 
    raise(MyError(3*2,"error occured")) 

# Value of Exception is stored in error 
except MyError as error: 
    print(error) #printing the Myerror object in user defined printing __str__
