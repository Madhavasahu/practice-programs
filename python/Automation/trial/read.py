import serial
import time
import sys
import binascii
from datetime import datetime

configuredPort = serial.Serial('/dev/ttyACM0', 460800, timeout=0, writeTimeout=0)
def readPacket():
    configuredPort.flushInput()  
    configuredPort.flushOutput() 
    serialBuffer = []
    while True:
        size =  configuredPort.inWaiting()
        if size > 0:
            response = str(binascii.hexlify( configuredPort.read()).decode('utf-8'))
            if (response == 'ba'):
                break
            else:
                serialBuffer.append(response)
    print(serialBuffer,flush=True)
    print(datetime.now().strftime("%X")) 
    serialBuffer = []

def main():
    try:
        while True:
            time.sleep(0.5)
            readPacket()
    except Exception as  error:
        print ("error while communicating...: " + str(error))
    finally:
        configuredPort.close()

if __name__ == "__main__":
    main()
