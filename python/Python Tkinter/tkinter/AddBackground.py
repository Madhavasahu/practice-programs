from tkinter import *

my_window = Tk()
my_window.title("my window")
#my_window.configure(width=500,height=500,bg='#00ff00')
my_window.geometry("500x500+500+100")
my_window.resizable(width=True, height=False)
my_window.mainloop()