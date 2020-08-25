from tkinter import *
from tkinter import messagebox
def main():
    root = Tk()
    root.wm_title("Main Window")
    root.geometry("500x500")
    messagebox.showwarning("msg Box","tkitner message box")
    t1=Toplevel(root)
    t1.geometry("100x100")
    root.mainloop()
if __name__ == "__main__":
    main()