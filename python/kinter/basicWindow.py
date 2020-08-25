from tkinter import *
window = Tk()
window.geometry("300x300")
window.title("Main Window")
label1 = Label(window,relief='solid',text="Welcome to Tkinter",fg='red',bg='yellow',font=("arial",16,"bold"))
label1.pack()
button1 = Button(window,relief='raised',text="Click here",fg='blue',bg='white',font=("arial",10,"bold"))
button1.pack()
window.mainloop()