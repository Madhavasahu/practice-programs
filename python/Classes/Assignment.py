class Account():
    def __init__(self,owner='',balance=0):
        self.owner = owner
        self.balance = balance
    def __str__(self):
        return self.owner
    def deposit(self,amount):
        self.balance +=amount
        print("Deposited "+str(amount))
    def withdraw(self,amount):
        if amount > self.balance:
            print("funds are unavailable")
            print("Current balance is "+str(self.balance))
        else:
            self.balance -= amount
            print("Withdrawn "+str(amount))
    def balanceCheck(self):
        print("Balance is "+str(self.balance))
    def __del__(self):
        print(self.owner + " account deleted")
    def deleteAccount(self):
        del self
def createAccount():
    print("Enter your name: ")
    user = input()
    print("Enter you opening Balance: ")
    openingBal = int(input())
    return Account(user,openingBal)
    
def main():
    ac = Account('antman',1000)
    ac.deposit(45455)
    ac.balanceCheck()
    ac.deleteAccount()
    '''print("1 : CreateAccount\n")
    print("2 : BalanceCheck\n")
    print("3 : Deposit\n")
    print("4 : Withdraw\n")
    print("5 : DeleteAccount\n")
    while(1):
        userInput = input("What do you want to do ?")
        if (userInput == '1'):
            account = createAccount()
            account.deleteAccount()
        elif (userInput == '2'):
            account.balanceCheck()
        elif (userInput == '3'):
            print("Enter the amount: ")
            amount = int(input())
            account.deposit(amount)
        elif (userInput == '4'):
            print("Enter the amount: ")
            amount = int(input())
            account.withdraw(amount)
        elif (userInput == '5'):
            account.deleteAccount()
        elif (userInput == 'exit') | (userInput == 'EXIT'):
            break
        else:
            print("Enter valid input")
            '''
if __name__ == "__main__":
    main()