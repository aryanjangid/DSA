A = []
B = []
C = []
D = []
E = []

nA = int(input("Enter the number of elements in the set A"))
for i in range(nA):
    v = int(input("Enter the element"))
    A.append(v)
nB = int(input("Enter the number of elements in the set B"))
for i in range(nB):
    v = int(input("Enter the element"))
    B.append(v)

def interAB():
    for i in A:
        if i in B:
            C.append(i)
    print(C)

def unionAB():
    for i in A:
        D.append(i)
    for i in B:
        if i not in A:
            D.append(i)
    print(D)


def diffAB():
    for i in A:
        if i not in B:
            E.append(i)
    print(E)

print("******Menu******")
print("1. Intersection of set A and B")
print("2. Union of set A and B")
print("3. Difference of set A and B")
print("4. Exit")

while(True):
    ch = int(input("Enter any option from the menu : "))
    if (ch == 1):
        interAB();
    elif (ch == 2):
        unionAB();
    elif (ch == 3):
        diffAB();
    else:
        break;