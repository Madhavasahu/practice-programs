def divide(a,b):
    try:
        return a/b 
    except ZeroDivisionError as e:
        print(e)
print(divide(23, 32))
print(divide(2,3))
print(divide(2,0))  #gives ZeroDivisionError: division by zero exception
print(divide(10,2))