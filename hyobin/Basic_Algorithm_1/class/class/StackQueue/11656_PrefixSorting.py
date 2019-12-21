s = input()
mylist = []

for i in range(len(s)) :
    mylist.append(s[i:])

mylist.sort()

for e in mylist:
    print(e)