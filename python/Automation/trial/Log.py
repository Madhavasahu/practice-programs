import binascii
import time
import os
import serial
from datetime import datetime
import sys
import mysql.connector

#To run this program enter command :python Log.py <comport> <baudrate> <maintime> <subtime>
#For example python Log.py /dev/ttyACM0 460800 1:1:1 0:0:1 will logs the data for 1hr1min1sec with 1sec logging frequency, 460800 baudrate.

class Database:
    def __init__(self,database):    
        self.database = database
        self.createDatabase()

    def createDatabase(self):
        self.mydb = mysql.connector.connect(host = "localhost", user = "root",passwd = "12345678")
        self.mycursor = self.mydb.cursor()
        command = "CREATE DATABASE IF NOT EXISTS "+self.database
        self.mycursor.execute(command)
        self.mycursor.close()
        self.mydb = mysql.connector.connect(host = "localhost", user = "root",passwd = "12345678",database = self.database)
        command = "CREATE TABLE IF NOT EXISTS NodePacketData (id INT PRIMARY KEY AUTO_INCREMENT, timestamp TIME, BATvoltage DECIMAL(5,3) UNSIGNED,BATcurrent DECIMAL (5,3) UNSIGNED, LEDvoltage DECIMAL (5,3) UNSIGNED, LEDcurrent DECIMAL (5,3) UNSIGNED,PANELcurrent DECIMAL (5,3) UNSIGNED, PANELvoltage DECIMAL (5,3) UNSIGNED, LEDintesity INT UNSIGNED, DCDCFault INT UNSIGNED,LampFault INT UNSIGNED, PanelFault INT UNSIGNED, ACDCFault INT UNSIGNED, PWRsrc INT UNSIGNED)"
        self.mycursor = self.mydb.cursor()
        self.mycursor.execute(command)

    def storeInDatabase(self,Node):
        command = "INSERT INTO NodePacketData (timestamp, BATvoltage, BATcurrent, LEDvoltage, LEDcurrent, PANELcurrent, PANELvoltage, LEDintesity, DCDCFault, LampFault, PanelFault, ACDCFault, PWRsrc) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)"
        values = [(str(Node.timeStamp[0]),Node.BATvoltage,Node.BATcurrent,Node.LEDvoltage,Node.LEDcurrent,Node.PANELcurrent,Node.PANELvoltage,Node.LEDintesity,Node.DCDCFault,Node.LampFault,Node.PanelFault,Node.ACDCFault,Node.PWRsrc)]
        self.mycursor.executemany(command, values)
        self.mydb.commit()
class Node(object):
    def __init__(self):
        """This is the class for storing Node packet data."""
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
        """Clears the already fetched node packet data after logging."""
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
    """Class for Logging the serial port data."""
    def __init__(self,comport='/dev/ttyACM0',baudRate=115200,maintime="0:0:10", subtime="0:0:1"):
        self.node            = Node()
        self.database        = Database("Node")
        self.serialBuffer    = []
        self.COMvar          = comport
        self.configuredPort  = 'None'
        self.maintime        = maintime
        self.subtime         = subtime
        self.baudRate        = baudRate

    def calcTime(self):
        """Calculates maintime and subtime in sec as per the user given inputs which are in x:x:x format """
        tempmain = self.maintime.split(':')
        tempsub  = self.subtime.split(':')
        temp1    = (int(tempmain[0]) * 60 * 60) + (int(tempmain[1]) * 60) + (int(tempmain[2]))
        temp2    = (int(tempsub[0]) * 60 * 60) + (int(tempsub[1]) * 60) + (int(tempsub[2]))
        return (temp1, temp2)

    def openPort(self):
        """Opens the COM port with given port(ex./dev/tty/ACM0), baudrate (460800)."""
        try:
            self.configuredPort = serial.Serial(self.COMvar, self.baudRate, timeout=0, writeTimeout=0)
            time.sleep(1)
        except serial.SerialException as e:
            print("error while connecting to COMport: " + str(e))
            sys.exit()
    
    def readPacket(self):
        """Reads the serial port byte by byte for every x secs given by user."""
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
            except Exception as  error:
                print ("error while communicating...: " + str(error))
            finally:
                self.configuredPort.close()
        else:
            print ("cannot open selected serial port ")

    def decodeToBinary(self, byte):
        """Decodes the given byte to binary"""
        binVal = ("{0:08b}".format(int(byte, 16))) 
        return binVal

    def decodeNodePacket(self):
        """Decodes the node packet from serial hex data."""
        if len(self.serialBuffer) >= 18:
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
                self.node.LEDvoltage    = int(self.serialBuffer[13], 16)                # take voltage as it is, remaining params compensate dividing by 10
                self.node.BATcurrent    = float((int(self.serialBuffer[14], 16)) / 10)
                self.node.BATvoltage    = float((int(self.serialBuffer[15], 16)) / 10)
                self.node.PANELcurrent  = float((int(self.serialBuffer[16], 16)) / 10)
                self.node.PANELvoltage  = float((int(self.serialBuffer[17], 16)) / 10)
                print("Received packet {} at {} ".format(self.serialBuffer,self.node.timeStamp[0]))
                              
    def writeToFile(self, fileName, parameter):
        """Write the given parameter to given file with timestamp."""
        with open(fileName, "a")  as fHandle:
            fHandle.write(str(self.node.timeStamp[0]) + "," + str(parameter) + "\n")

    def logPacket(self):
        '''Log the decoded node data to database'''
        self.database.storeInDatabase(self.node)
    def startLog(self, main, sub):
        """Funtion that runs the reading, decoding, clearing of serial data."""
        print("\nLogging data started\n")
        self.openPort()
        count       = 0
        maincount   = 0
        while True:
            time.sleep(0.5)
            self.readPacket()
            count  = count + 1
            if count == sub:
                self.decodeNodePacket()
                self.logPacket()
                count = 0
                maincount = maincount + 1   
            self.node.clearData()
            if maincount == int(main//sub):
                self.database.mycursor.close()
                break
        print("\nLogged data successfully")

def main():
    """Takes the user provided command line arguments and pas them to classes."""
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

    if os.path.exists('LEDcurrent.txt'):     #if any file exits in the local directory, delete all txt's
        if sys.platform   == 'win32':
            os.system("del *.txt /s 1>nul")  #deletes previous data without echoing in win32
        elif sys.platform == 'linux':
            os.system("rm -rf *.txt")
        else:
            print("unknown OS")
            return

    log              = DataLog(comport,baudRate, maintime, subtime)
    maintime,subtime = log.calcTime()

    try:
        assert(maintime >= subtime)
        log.startLog(maintime, subtime)
    except AssertionError:
        print("please provide valid time input")
    except KeyboardInterrupt:
        print("Exited")
        pass 

if __name__ == "__main__":
    main()
