class Dog():
    def __init__(self,name):
        self.name = name
    def speak(self):
        return self.name + "says bhouuu!"

class Cat():
    def __init__(self,name):
        self.name = name
    def speak(self):
        return self.name + "says meoww!"   

def printPet(petName):
    print(petName.speak())     
    
def main():
    puppy = Dog("pupy")
    cutie = Cat("cutie")
    printPet(puppy)
    printPet(cutie)
if __name__ == "__main__":
    main()