#This is a program to show the error incase of user calls the abstract method
class Animal():
    def __init__(self,name):
        self.name = name
    def speak(self):
        raise NotImplementedError("The child classes has to define speak()")
def main():
    dog = Animal(name = "puppy")
    dog.speak()
if __name__ == "__main__":
    main()