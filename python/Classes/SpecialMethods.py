#This is the program to show the special methods in python that work on user defined class objects
#__del__ method is called automatically after program ending.we can del the object for which the __del__ method is called
class Book():
    def __init__(self,title,author,price,pages):
        self.title = title
        self.author = author
        self.price = price
        self.pages = pages
    def __len__(self):
        return self.pages
    def __str__(self):
        return self.title +" by " +self.author
    def __del__(self):
        print ("A book object has been deleted")
book = Book('Python','Madhava',2000,100)
del book
