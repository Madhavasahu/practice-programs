from tkinter import *
import time
import re
import serial.tools.list_ports
import csv
from drawnow import *
import matplotlib.pyplot as plt
import datetime
from functools import partial
plt.ion()


class Graph(object):

    def __init__(self, master):
        self.graphBuffer = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        self.date = []
        self.parameter = []
        self.master = master

    def makeGraph(self):
        plt.plot(self.date, self.parameter, 'b^-')  
    
    def updateGraphBuffer(self, index):
        graphbuffer = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        graphbuffer[index] = 1
        print (graphbuffer[index])

        
class DataLog(object):

    def __init__(self, master):
        self.master = master 
        self.buffer = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        self.serialBuffer = ""
        self.baudRate = 460800
        self.portList = []
        self.COMvar = StringVar(master)
        self.configuredPort = 'None'
        self.csvHandle = csv.writer(open('data.csv', 'w'), delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    
    def findCOMPorts(self):
        comlist = serial.tools.list_ports.comports() 
        for element in comlist:
            self.portList.append(element.device)
    
    def connect(self):
        self.configuredPort = Serial(self.COMvar.get() , self.baudRate, timeout=0, writeTimeout=0)
    
    def start(self):
        self.configuredPort.write([str(item) for item in self.buffer])
        self.csvHandle.writerow(["TimeStamp", "Name", "Value"])
        self.master.after(100, self.master.readSerial)
    
    def stop(self):
        print("Not implemented yet\n")
        
    def disconnect(self):
        self.configuredPort.close()

        # print (self.configuredPort.is_open)
class AppWindow(object):

    def __init__(self, master):
        self.tempODR = ["1", "7", "12.5"]
        self.humODR = ["1", "7", "12.5", "25"]
        self.pressureOdr = ["1", "7", "12.5", "25"]
        self.xceleroOdr = ["10", "50", "119", "238", "476", "952"]
        self.xceleroFs = ["2", "4", "8", "16"]
        self.gyroOdr = ["15", "60", "119", "238", "476", "952"]
        self.gyroFs = ["245", "500", "2000"]
        self.magOdr = ["0.625", "1.25", "2.5", "5", "10", "20", "40", "80"]
        self.magFs = ["4", "8", "12", "16"]
        self.master = master
        self.checkButtonVar1 = IntVar()
        self.checkButtonVar2 = IntVar()
        self.checkButtonVar3 = IntVar()
        self.checkButtonVar4 = IntVar()
        self.checkButtonVar5 = IntVar()
        self.checkButtonVar6 = IntVar()
        self.optMenuVar1 = StringVar(master)
        self.optMenuVar2 = StringVar(master)
        self.optMenuVar3 = StringVar(master)
        self.optMenuVar4 = StringVar(master)
        self.optMenuVar5 = StringVar(master)
        self.optMenuVar6 = StringVar(master)
        self.optMenuVar7 = StringVar(master)
        self.optMenuVar8 = StringVar(master)
        self.optMenuVar9 = StringVar(master)
        self.dataLog = DataLog(master)
        self.graph = Graph(master)
        master.wm_title("Serial Terminal")
        self.dataLog.findCOMPorts() #error
        self.COMportsOptions = OptionMenu(master, self.dataLog.COMvar, self.dataLog.portList).grid(row=0, column=0)
        self.connectButton = Button(master, text="connect", command=self.dataLog.connect).grid(row=0, column=1, padx=10, pady=10)  # TO open the port
        self.startButton = Button(master, text="start", command=self.dataLog.start).grid(row=0, column=3, sticky=W, padx=10, pady=10)
        self.stopButton = Button(master, text="stop", command=self.dataLog.stop).grid(row=0, column=4, padx=10, pady=10)
        self.disconnectButton = Button(master, text="disconnect", command=self.dataLog.disconnect).grid(row=0, column=2, padx=10, pady=10)  # To close the port
        self.exitButton = Button(master, text="Exit", command=master.destroy).grid(row=0, column=8, padx=10, pady=10)  # Button to exit the window
        self.scrollbar = Scrollbar(master).grid(row=1, column=10)
        self.textLog = Text (master, width=30, height=6, takefocus=0).grid(row=1, column=9)  # error
        # self.textLog.config(yscrollcommand=self.scrollbar.set)
        # self.scrollbar.config(command=self.textLog.yview)
        self.tempLabel = Label(master, text="Temperature").grid(row=3, column=0, sticky=W, padx=5, pady=5)
        self.tempCheck = Checkbutton(master, variable=self.checkButtonVar1, command=partial(self.updateBuffer, var=self.checkButtonVar1,index=1)).grid(row=3, column=1, sticky=W, padx=5, pady=5)
        self.tempParam = Label(master, text="ODR").grid(row=4, column=0, sticky=W, padx=5, pady=5)
        self.optMenuVar1.set("1")
        self.tempOptions = OptionMenu(master, self.optMenuVar1, *self.tempODR).grid(row=4, column=1, sticky=W, padx=5, pady=5)
        self.tempButton = Button(master, text='Set', command=self.updateTempOdr).grid(row=4, column=2, sticky=W, padx=5, pady=5)
        
        self.humLabel = Label(master, text="Humidity").grid(row=3, column=5, sticky=W, padx=5, pady=5)
        self.humCheck = Checkbutton(master, variable=self.checkButtonVar2, command=partial(self.updateBuffer, var=self.checkButtonVar2,index=3)).grid(row=3, column=6, sticky=W, padx=5, pady=5)
        self.humParam = Label(master, text="ODR").grid(row=4, column=5, sticky=W, padx=5, pady=5)
        self.optMenuVar2.set("1")
        self.humOptions = OptionMenu(master, self.optMenuVar2, *self.humODR).grid(row=4, column=6, sticky=W, padx=5, pady=5)
        self.humButton = Button(master, text='Set', command=self.updateHumOdr).grid(row=4, column=7, sticky=W, padx=5, pady=5)
        
        self.pressLabel = Label(master, text="Pressure").grid(row=6, column=0, sticky=W, padx=5, pady=5)
        self.pressCheck = Checkbutton(master, variable=self.checkButtonVar3, command=partial(self.updateBuffer, var=self.checkButtonVar3,index=5)).grid(row=6, column=1, sticky=W, padx=5, pady=5)
        self.pressParam = Label(master, text="ODR").grid(row=7, column=0, sticky=W, padx=5, pady=5)
        self.optMenuVar3.set("1")
        self.pressOptions = OptionMenu(master, self.optMenuVar3, *self.pressureOdr).grid(row=7, column=1, sticky=W, padx=5, pady=5)
        self.pressButton = Button(master, text='Set', command=self.updatePressOdr).grid(row=4, column=7, sticky=W, padx=5, pady=5)

        self.xceleroLabel = Label(master, text="Accelerometer").grid(row=6, column=5, sticky=W, padx=5, pady=5)
        self.xceleroCheck = Checkbutton(master, variable=self.checkButtonVar4, command=partial(self.updateBuffer, var=self.checkButtonVar4,index=7)).grid(row=6, column=6, sticky=W, padx=5, pady=5)
        self.xceleroParam = Label(master, text="ODR").grid(row=7, column=5, sticky=W, padx=5, pady=5)
        self.optMenuVar4.set("10")
        self.xceleroOptions = OptionMenu(master, self.optMenuVar4, *self.xceleroOdr).grid(row=7, column=6, sticky=W, padx=5, pady=5)
        self.xceleroButton = Button(master, text='Set', command=self.updateXceleroOdr).grid(row=7, column=7, sticky=W, padx=5, pady=5)
        
        self.xceleroLabel2 = Label(master, text="FullScale").grid(row=8, column=5, sticky=W, padx=5, pady=5)
        self.optMenuVar5.set("2")
        self.xceleroOptions2 = OptionMenu(master, self.optMenuVar5, *self.xceleroFs).grid(row=8, column=6, sticky=W, padx=5, pady=5)
        self.xceleroButton2 = Button(master, text='Set', command=self.updateXceleroFs).grid(row=8, column=7, sticky=W, padx=5, pady=5)
 
        self.gyrooLabel = Label(master, text="Gyrometer").grid(row=10, column=0, sticky=W, padx=5, pady=5)
        self.gyroCheck = Checkbutton(master, variable=self.checkButtonVar5, command=partial(self.updateBuffer, var=self.checkButtonVar5,index=10)).grid(row=10, column=1, sticky=W, padx=5, pady=5)
        self.gyroParam = Label(master, text="ODR").grid(row=7, column=5, sticky=W, padx=5, pady=5)
        self.optMenuVar6.set("15")
        self.gyroOptions = OptionMenu(master, self.optMenuVar6, *self.gyroOdr).grid(row=11, column=1, sticky=W, padx=5, pady=5)
        self.gyroButton = Button(master, text='Set', command=self.updategyroOdr).grid(row=11, column=2, sticky=W, padx=5, pady=5)
        
        self.gyroLabel2 = Label(master, text="FullScale").grid(row=12, column=0, sticky=W, padx=5, pady=5)
        self.optMenuVar7.set("245")
        self.gyroroOptions2 = OptionMenu(master, self.optMenuVar7, *self.gyroFs).grid(row=12, column=1, sticky=W, padx=5, pady=5)
        self.gyroButton2 = Button(master, text='Set', command=self.updateGyroFs).grid(row=12, column=2, sticky=W, padx=5, pady=5)
    
        self.magLabel = Label(master, text="Magnetometer").grid(row=10, column=5, sticky=W, padx=5, pady=5)
        self.magCheck = Checkbutton(master, variable=self.checkButtonVar6, command=partial(self.updateBuffer, var=self.checkButtonVar6,index=13)).grid(row=10, column=6, sticky=W, padx=5, pady=5)
        self.magParam = Label(master, text="ODR").grid(row=11, column=5, sticky=W, padx=5, pady=5)
        self.optMenuVar8.set("0.625")
        self.magOptions = OptionMenu(master, self.optMenuVar8, *self.magOdr).grid(row=11, column=6, sticky=W, padx=5, pady=5)
        self.magButton = Button(master, text='Set', command=self.updateMagOdr).grid(row=11, column=7, sticky=W, padx=5, pady=5)
        
        self.magLabel2 = Label(master, text="FullScale").grid(row=12, column=5, sticky=W, padx=5, pady=5)
        self.optMenuVar9.set("4")
        self.gyroroOptions2 = OptionMenu(master, self.optMenuVar9, *self.magFs).grid(row=12, column=6, sticky=W, padx=5, pady=5)
        self.gyroButton2 = Button(master, text='Set', command=self.updateMagFs).grid(row=12, column=7, sticky=W, padx=5, pady=5)
      
        self.graphLabel = Label(master, text="Graphs").grid(row=13, column=3, sticky=W, padx=5, pady=5)
        self.graphtemp = Button(master, text='Temp', command=partial(self.graph.updateGraphBuffer, index=0)).grid(row=15, column=0, sticky=W, padx=5, pady=5)
        self.graphHum = Button(master, text='Humi', command=partial(self.graph.updateGraphBuffer, index=1)).grid(row=15, column=1, sticky=W, padx=5, pady=5)
        Button(master, text='Press', command=partial(self.graph.updateGraphBuffer, index=2)).grid(row=15, column=2, sticky=W, padx=5, pady=5)
        Label(master, text="Accelerometer").grid(row=14, column=4)
        Button(master, text='x', command=partial(self.graph.updateGraphBuffer, index=3)).grid(row=15, column=3)
        Button(master, text='y', command=partial(self.graph.updateGraphBuffer, index=4)).grid(row=15, column=4)
        Button(master, text='z', command=partial(self.graph.updateGraphBuffer, index=5)).grid(row=15, column=5)
        Label(master, text="Gyrometer").grid(row=14, column=8)
        Button(master, text='x', command=partial(self.graph.updateGraphBuffer, index=6)).grid(row=15, column=7)
        Button(master, text='y', command=partial(self.graph.updateGraphBuffer, index=7)).grid(row=15, column=8)
        Button(master, text='z', command=partial(self.graph.updateGraphBuffer, index=8)).grid(row=15, column=9)
        Label(master, text="Magnetometer").grid(row=14, column=11)
        Button(master, text='x', command=partial(self.graph.updateGraphBuffer, index=9)).grid(row=15, column=10)
        Button(master, text='y', command=partial(self.graph.updateGraphBuffer, index=10)).grid(row=15, column=11)
        Button(master, text='z', command=partial(self.graph.updateGraphBuffer, index=10)).grid(row=15, column=12)

    def updateMagOdr(self):
        if self.optMenuVar.get() == "0.625":
            self.dataLog.buffer[14] = 1
        elif self.optMenuVar.get() == "1.25":
            self.dataLog.buffer[14] = 2
        elif self.optMenuVar.get() == "2.5":
            self.dataLog.buffer[14] = 3
        elif self.optMenuVar.get() == "5":
            self.dataLog.buffer[14] = 4
        elif self.optMenuVar.get() == "10":
            self.dataLog.buffer[14] = 5
        elif self.optMenuVar.get() == "20":
            self.dataLog.buffer[14] = 6
        elif self.optMenuVar.get() == "40":
            self.dataLog.buffer[14] = 7
        else:
            self.dataLog.buffer[14] = '8'

    def updateMagFs(self):
        if self.optMenuVar.get() == "4":
            self.dataLog.buffer[15] = 1
        elif self.optMenuVar.get() == "8":
            self.dataLog.buffer[15] = 2
        elif self.optMenuVar.get() == "12":
            self.dataLog.buffer[15] = 3
        else:
            self.dataLog.buffer[15] = 4
    
    def updateGyroFs(self):
        if self.optMenuVar.get() == "245":
            self.dataLog.buffer[12] = 1
        elif self.optMenuVar.get() == "500":
            self.dataLog.buffer[12] = 2
        else:
            self.dataLog.buffer[12] = 3

    def updategyroOdr(self):
        if self.optMenuVar.get() == "15":
            self.dataLog.buffer[11] = 1
        elif self.optMenuVar.get() == "50":
            self.dataLog.buffer[11] = 2
        elif self.optMenuVar.get() == "119":
            self.dataLog.buffer[11] = 3
        elif self.optMenuVar.get() == "238":
            self.dataLog.buffer[11] = 4
        elif self.optMenuVar.get() == "476":
            self.dataLog.buffer[11] = 5
        else:
            self.dataLog.buffer[11] = 6
             
    def updateXceleroFs(self):
        if self.optMenuVar.get() == "2":
            self.dataLog.buffer[9] = 1
        elif self.optMenuVar.get() == "4":
            self.dataLog.buffer[9] = 2
        elif self.optMenuVar.get() == "8":
            self.dataLog.buffer[9] = 3
        else:
            self.dataLog.buffer[9] = 4

    def updateXceleroOdr(self):
        if self.optMenuVar.get() == "10":
            self.dataLog.buffer[8] = 1
        elif self.optMenuVar.get() == "50":
            self.dataLog.buffer[8] = 2
        elif self.optMenuVar.get() == "119":
            self.dataLog.buffer[8] = 3
        elif self.optMenuVar.get() == "238":
            self.dataLog.buffer[8] = 4
        elif self.optMenuVar.get() == "476":
            self.dataLog.buffer[8] = 5
        else:
            self.dataLog.buffer[8] = 6

    def updatePressOdr(self):
        if self.optMenuVar.get() == "1":
            self.dataLog.buffer[6] = 1
        elif self.optMenuVar.get() == "7":
            self.dataLog.buffer[6] = 2
        elif self.optMenuVar.get() == "12.5":
            self.dataLog.buffer[6] = 3
        else:
            self.dataLog.buffer[4] = 4
            
    def updateHumOdr(self):
        if self.optMenuVar.get() == "1":
            self.dataLog.buffer[4] = 1
        elif self.optMenuVar.get() == "7":
            self.dataLog.buffer[4] = 2
        elif self.optMenuVar.get() == "12.5":
            self.dataLog.buffer[4] = 3
        else:
            self.dataLog.buffer[4] = 4    

    def updateTempOdr(self):
        if self.optMenuVar.get() == "1":
            self.dataLog.buffer[2] = 1
        elif self.optMenuVar.get() == "7":
            self.dataLog.buffer[2] = 2
        elif self.optMenuVar.get() == "12.5":
            self.dataLog.buffer[2] = 3
        
    def updateBuffer(self, index,var):
        self.dataLog.buffer[index] = var.get()
        print(self.dataLog.buffer[index])   

    def process(self, name, value):
        for index in range(6):
            currentDate = str(datetime.datetime.now().time())
            self.dataLog.csvHandle.writerow([currentDate, name, value])
            if self.graph.graphbuffer[index] == 1:
                self.graph.date.append(currentDate)
                self.graph.parameter.append(value)       
                drawnow(self.graph.makegraphs)
                plt.pause(0.000001)

    def readSerial(self):
        while True:
            readByte = self.configuredPort.read()
            if len(readByte) == 0:
                break
            if readByte == '\r':
                readByte = '' 
            if readByte == '\n':
                self.dataLog.textLog.insert('0.0', self.dataLog.serialBuffer)
            print(self.dataLog.serialBuffer + "\n\n\n")
            self.dataLog.textLog.insert('0.0', "\n")
            if self.dataLog.serialBuffer.find(':') > 0:
                name, value = self.dataLog.serialBuffer.split(':', 1)
                name = name.strip()
                value = value.strip()
                value1 = re.findall(r"[-+]?\d*\.\d+|\d+", value)
                value2 = [float(i) for i in value1]
                temp = value2
                self.process(name, temp)
            self.dataLog.serialBuffer = ""  # empty the buffer
        else:
            self.dataLog.serialBuffer += readByte  # add to the buffer
        self.master.after(10, self.readSerial)  # check serial again soon


master = Tk()
objec = AppWindow(master)
master.mainloop()
