class MyException(Exception):
    pass

def func(num):
    try:
        return int(num)/2
        #raise MyException("custom exception")
    except (ValueError,SyntaxError) as e: #catching multiple exceptions in a single line
        print("error occured: {}".format(e))
    except TypeError as e:
        print(e)
    except MyException as e:
        #print("Failed due to "+e.msg+" error no: "+str(e.errorno))
        print(e)   
        #raise  raise statement can be used to rethrow the exception so that the caller can handle it
    #except:  #generic exception for all other conditions
     #   print("something went wrong")

   
print(func("d"))
print(func("23"))
