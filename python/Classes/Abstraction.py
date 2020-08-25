class Animal:
    def __init__(self,name):
        self.name = name
    def speak(self):
        raise NotImplementedError("The childen classes has to define speak()")
    
class Dog(Animal):
    def __init__(self, name):
        Animal.__init__(self, name)
    def speak(self):
        print("I am "+self.name)
        
class Cat(Animal):
    def __init__(self,name):
        Animal.__init__(self, name)
    def speak(self):
        print("I am "+self.name)
        
def main():
    dog = Dog(name = "Puppy")
    dog.speak()
    cat = Cat(name = "Cutie")
    cat.speak()
    
if __name__ == "__main__":
    main()