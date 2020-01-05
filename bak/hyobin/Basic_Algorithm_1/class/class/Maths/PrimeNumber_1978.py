N = int(input())
mylist = [int(x) for x in input().split()]
    
mylist.sort()

count = [False for i in range(mylist[N-1])]
pn = 0

for i in range (2,mylist[N-1]+1):
    if count[i-1] == False :
        if i in mylist:
            pn=pn+1;
        for j in range (i*2, mylist[N-1]+1, i):
            count[j-1] = True

print(pn)