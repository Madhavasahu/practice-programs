import matplotlib.pyplot as plt
import matplotlib.animation as animation
import sys
from matplotlib.ticker import FormatStrFormatter
fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)
def plotDataOf(i,file):
    try:
        lines = open(file,"r").read()
    except Exception:
        print("error while reading the files")
    lines = lines.split('\n')
    xlist = []
    ylist = []
    for eachLine in lines:
        if len(eachLine)>1:
            x,y = eachLine.split(',')
            xlist.append(int(x))
            ylist.append(float(y))
    ax1.clear()
    ax1.grid()
    ax1.xaxis.set_major_formatter(FormatStrFormatter('%.0f'))
    plt.subplots_adjust(bottom=0.2)
    ax1.plot(xlist,ylist)
    plt.xticks(rotation=45, ha='right')
    plt.title(file.split('.')[0])
    plt.ylabel('Data')

def userMenu():
    print("Enter your choice :: ",end="")
    print("""    1:LED voltage
                         2:LED current
                         3.Battery voltage
                         4.Battery current
                         5.LED intensity
                         6.Lamp fault
                         7.Power source
                         8.Panel fault
                         9.ACDC fault
                         10.DCDC fault
                         11.PANEL current
                         12.PANEL voltage""")
    print(">>",end="")
    choice = input()  
    if choice == '1':
        file ="LEDvoltage.txt"
    elif choice == '2':
        file = "LEDcurrent.txt"
    elif choice == '3':
        file = "BATvoltage.txt"
    elif choice == '4':
        file = "BATcurrent.txt"
    elif choice == '5':
        file = "LEDintesity.txt"
    elif choice == '6':
        file = "LampFault.txt"
    elif choice == '7':
        file = "PWRsrc.txt"
    elif choice == '8':
        file = "PanelFault.txt"
    elif choice == '9':
        file = "ACDCFault.txt"
    elif choice == '10':
        file = "DCDCFault.txt"
    elif choice == '11':
        file = "PANELcurrent.txt"
    elif choice == '12':
        file = "PANELvoltage.txt"
    else:
        print("provide correct choice\n")
        sys.exit()
    return file

def main():
    userFile = userMenu()
    try:
        ani=animation.FuncAnimation(fig, plotDataOf,fargs=[userFile], interval=1000)
        plt.show()
    except Exception as e:
        print(e)

if __name__ =="__main__":
    main()
    