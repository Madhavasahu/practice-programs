from tkinter import *
root=Tk()
root.title("a scroll bar")
root.geometry("100x100")
list = Listbox(root, height=10, width=15)
scroll = Scrollbar(root, command=list.yview)
list.configure(yscrollcommand=scroll.set)
list.pack(side=LEFT)
scroll.pack(side=RIGHT, fill=Y)
for item in range(30):
    list.insert(END,item)
root.mainloop()