from tkinter import *
from serial import *
import serial.tools.list_ports
connected = []
portNumber = 0
ODR = [1, 2, 3, 4]

def ConfigPort():
    try:
        cfgPort = Serial(port=portNumber, baudrate=9600,\
                    parity=serial.PARITY_NONE,\
                    stopbits=serial.STOPBITS_ONE, bytesize=serial.EIGHTBITS)
        print(portNumber)
    except Exception:
        print("Unable to connect to the selected port")

def findCOMPorts():   
    comlist = serial.tools.list_ports.comports() 
    for element in comlist:
        connected.append(element.device)


def getPort(value):
    global portNumber
    portNumber = value
    print("Selected port is {0}".format(value)) 


def getSensor1():
    print("the return value is {}".format(var_check1.get()))

    
def getSensor2():
    print("the return value is {}".format(var_check2.get()))


def getOdr(var2):
    print("the selected ODR is {}".format(var2))


# create a window
master = Tk()
master.geometry("500x500")
master.title("List of Ports")

# have a var
var1 = StringVar(master)
var1.set("select")  # default port as unknown
var2 = StringVar(master)
var2.set("select")
var_check1 = IntVar(master)
var_check2 = IntVar(master)
# start execution
try:
    findCOMPorts()
    optMenu1 = OptionMenu(master, var1, *connected, command=getPort)
    optMenu1.pack()
    optMenu2 = OptionMenu(master, var2, *ODR, command=getOdr)
    optMenu2.pack()
    button = Button(master, text="Connect", fg="blue", bg="white", command=ConfigPort)
    button.pack()
    check1 = Checkbutton(master, text="Temp", variable=var_check1, command=getSensor1)
    check1.pack()
    check2 = Checkbutton(master, text="Hum", variable=var_check2, command=getSensor2)
    check2.pack()
    master.mainloop()
except TypeError:
        print("Please connect the hardware")
        exit()