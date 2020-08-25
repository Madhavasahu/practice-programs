import threading

def printit():

  print ("Hello, World!")

threading.Timer(1.0, printit).start()
