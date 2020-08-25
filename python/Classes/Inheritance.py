class Animal():
    def __init__(self):
        print("ANIMAL CREATED")
    def whoAmI(self):
        print("I am an Animal")
    def eat(self):
        print("I am eating")

class Dog(Animal): #syntax for inheriting
    def __init__(self):
        Animal.__init__(self)
        print("Dog created")
    def whoAmI(self):
        print("I am a Dog")
    def bark(self):
        print("bhouuu....!!")
        
def main():
    myDog = Dog()
    myDog.whoAmI()
    myDog.eat()
    myDog.bark()

if __name__ == "__main__":
    main()