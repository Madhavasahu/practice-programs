import binascii
import time
import os
import serial
from datetime import datetime
import sys
import threading

class Node(object):
    def __init__(self):
        self.LEDintesity    = 0
        self.LEDcurrent     = 0.00
        self.LEDvoltage     = 0.00
        self.BATvoltage     = 0.00
        self.BATcurrent     = 0.00
        self.DCDCFault      = 0
        self.LampFault      = 0
        self.PanelFault     = 0
        self.ACDCFault      = 0
        self.PWRsrc         = 0
        self.timeStamp      = []
        self.PANELcurrent   = 0.0
        self.PANELvoltage   = 0.0
        
    def clearData(self):
        self.LEDintesity    = 0
        self.LEDcurrent     = 0.00
        self.LEDvoltage     = 0.00
        self.BATvoltage     = 0.00
        self.BATcurrent     = 0.00
        self.DCDCFault      = 0
        self.LampFault      = 0
        self.PanelFault     = 0
        self.ACDCFault      = 0
        self.PWRsrc         = 0
        self.PANELcurrent   = 0.0
        self.PANELvoltage   = 0.0
        self.timeStamp.clear()
        
class DataLog(object):
    def __init__(self,comport='COM4',baudRate=115200,maintime="0:0:10", subtime="0:0:1"):
        self.node            = Node()
        self.serialBuffer    = []
        self.COMvar          = comport
        self.configuredPort  = 'None'
        self.maintime        = maintime
        self.subtime         = subtime
        self.baudRate        = baudRate
    def calcTime(self):
        tempmain = self.maintime.split(':')
        tempsub  = self.subtime.split(':')
        temp1    = (int(tempmain[0]) * 60 * 60) + (int(tempmain[1]) * 60) + (int(tempmain[2]))
        temp2    = (int(tempsub[0]) * 60 * 60) + (int(tempsub[1]) * 60) + (int(tempsub[2]))
        return [temp1, temp2]

    def connectToPort(self):
        try:
            self.configuredPort = serial.Serial(self.COMvar, self.baudRate, timeout=2, writeTimeout=0)
            time.sleep(1)
        except serial.SerialException as e:
            print("error while connecting to COMport: " + str(e))
            sys.exit()
    
    def readByte(self):
        threading.Timer(7.0, self.readByte).start()
        print("asdf_")
        self.node.clearData()
        self.serialBuffer = []
        try: 
            if not self.configuredPort.isOpen():
                self.configuredPort.open()
        except Exception as  e:
            print ("error while opening serial port: " + str(e))
            sys.exit()
        if self.configuredPort.isOpen():
            try:
                self.configuredPort.flushInput()  
                self.configuredPort.flushOutput() 
                self.serialBuffer = []
                while True:
                    size = self.configuredPort.inWaiting()
                    if size > 0:
                        response = str(binascii.hexlify(self.configuredPort.read()).decode('utf-8'))
                        if (response == 'ba'):
                            break
                        else:
                            self.serialBuffer.append(response)
                print(self.serialBuffer)
            except Exception as  error:
                print ("error while communicating...: " + str(error))
            finally:
                self.configuredPort.close()
        else:
            print ("cannot open selected serial port ")

    def decodeToBinary(self, byte):
            binVal = ("{0:08b}".format(int(byte, 16)))  # converts to binary
            return binVal
            # print(int(temp[1:],2)) #converts to decimal 0 th bit is not used here
            
    def decodeNodePacket(self):
        if len(self.serialBuffer) > 0:
            if self.serialBuffer[0] == 'ab' and self.serialBuffer[1] == 'ab':
                # print("correct data")
                # cmdcode = self.serialBuffer[2] #gets cmdcode as string
                # print("command code :",cmdcode)
                dateTimeObj             = datetime.now() 
                self.node.timeStamp.append(int(dateTimeObj.strftime("%X").replace(":","")))
                self.node.LEDintesity   = int(self.decodeToBinary(self.serialBuffer[3])[1:], 2)  # converts bin->select bins->then convert bins to decimal, 0 th bit is not used here
                self.node.PWRsrc        = int(self.decodeToBinary(self.serialBuffer[4])[6:], 2)
                self.node.ACDCFault     = int(self.decodeToBinary(self.serialBuffer[4])[3], 2)
                self.node.PanelFault    = int(self.decodeToBinary(self.serialBuffer[4])[2], 2)
                self.node.LampFault     = int(self.decodeToBinary(self.serialBuffer[4])[1], 2)
                self.node.DCDCFault     = int(self.decodeToBinary(self.serialBuffer[4])[0], 2)
                self.node.LEDcurrent    = float((int(self.serialBuffer[12], 16)) / 10)  # divide by 10 to compensate calc in the firmware
                self.node.LEDvoltage    = int(self.serialBuffer[13], 16)  # take voltage as it is
                self.node.BATcurrent    = float((int(self.serialBuffer[14], 16)) / 10)
                self.node.BATvoltage    = float((int(self.serialBuffer[15], 16)) / 10)
                self.node.PANELcurrent  = float((int(self.serialBuffer[16], 16)) / 10)
                self.node.PANELvoltage  = float((int(self.serialBuffer[17], 16)) / 10)
                #print("Received packet {} at {} ".format(self.serialBuffer,self.node.timeStamp[0]))
                return 'OK'
              
    def writeToFile(self, fileName, parameter):
        with open(fileName, "a")  as fHandle:
            fHandle.write(str(self.node.timeStamp[0]) + "," + str(parameter) + "\n")
    def logPacket(self):
        self.writeToFile("LEDintesity.txt",  self.node.LEDintesity)
        self.writeToFile("LEDcurrent.txt",    self.node.LEDcurrent) 
        self.writeToFile("LEDvoltage.txt",    self.node.LEDvoltage) 
        self.writeToFile("BATvoltage.txt",    self.node.BATvoltage) 
        self.writeToFile("BATcurrent.txt",    self.node.BATcurrent) 
        self.writeToFile("DCDCFault.txt",      self.node.DCDCFault) 
        self.writeToFile("LampFault.txt",      self.node.LampFault) 
        self.writeToFile("PanelFault.txt",    self.node.PanelFault) 
        self.writeToFile("ACDCFault.txt",      self.node.ACDCFault) 
        self.writeToFile("PWRsrc.txt",            self.node.PWRsrc)
        self.writeToFile("PANELcurrent.txt",self.node.PANELcurrent) 
        self.writeToFile("PANELvoltage.txt",self.node.PANELvoltage)
    def startLog(self, main, sub):
        self.readByte()
'''     while True:
           self.readByte()
            if self.decodeNodePacket()=='OK':
                print("PASS {}".format(self.serialBuffer))
            else:
                print("FAIL {}".format(self.serialBuffer))
            self.node.clearData()
            time.sleep(2)
'''
def main():
    if len(sys.argv) != 5:
        print("usage: comport baudrate maintime subtime")
        return
    print("Given comport  : {}".format(sys.argv[1]))
    print("Given baudrate : {}".format(sys.argv[2]))
    print("Given maintime : {}".format(sys.argv[3]))
    print("Given subtime  : {}".format(sys.argv[4]))

    comport   = sys.argv[1]
    baudRate  = sys.argv[2]
    maintime  = sys.argv[3]
    subtime   = sys.argv[4]
    if os.path.exists('LEDcurrent.txt'):  # if any file exits in the local directory, delete all txt's
        if sys.platform =='win32':
            os.system("del *.txt /s 1>nul")  #deletes previous data without echoing
        elif sys.platform =='linux':
            os.system("rm -rf *.txt")
        else:
            print("unknown OS")
            return
    log       = DataLog(comport,baudRate, maintime, subtime)
    log.connectToPort()
    finalTime = log.calcTime()
    try:
        assert(finalTime[0] >= finalTime[1])
        log.startLog(finalTime[0], finalTime[1])
    except AssertionError:
        print("please provide valid time input")
    except KeyboardInterrupt:
        print("Exited")
        pass 
if __name__ == "__main__":
    main()
