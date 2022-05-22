from matplotlib.pyplot import table


table=[]

def hashtable():
    tablesize=int(intput("Enter the Size of the hash table :"))
    table.append(none*tablesize)
    # for i in range (0,tablesize):
    #     table.append(0)
    # for i in range (0,tablesize):
    print(table)

def search(number):
    print(number)


choice1=0
while(choice1!=2):
    print("************************")
    print("1. Linear Probing      *")
    print("2. Exit                *")
    print("************************")
    choice1=int(input("Enter Choice: "))
    if(choice1>2):
        print("Enter a valid number")
    
    if(choice1==1):
        hashtable()
        choice2=0
        while(choice2!=4):
            print("************************")
            print("1. Insert              *")
            print("2. Search              *")
            print("3. Display             *")
            print("4. Back                *")
            print("************************")

        