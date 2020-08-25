from tkinter import *

root = Tk()
root2 = Toplevel(root)
root.title("SevyaMM")
root2.title("SevyaCS")
windWidth = 600
windHeight = 500
screenWidth = root.winfo_screenmmwidth()

screenHeight =root.winfo_screenmmheight()
print(screenHeight)
x = (screenWidth/2)-(screenWidth/2)
y = (screenHeight/2)-(screenHeight/2)
root.geometry("%dx%d+%d+%d" % (windWidth,windHeight,x,y))


root.mainloop()