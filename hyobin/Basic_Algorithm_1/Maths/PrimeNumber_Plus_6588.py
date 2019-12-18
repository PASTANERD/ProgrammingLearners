mylist = []
while(True) :
    element = int(input())
    if element == 0 : break
    mylist.append(element)

M = max(mylist)

count = [False for _ in range(M+1)]

for i in range(2,M+1):
    if count[i]==False :
        for j in range(i*2, M+1,i):
            count[j] = True
            

for n in mylist :
    nmax = 0;
    b = 0;
    for a in range(2,M+1): 
        if count[a] == False and a<n-1 : 
            if count[n-a] == False :
                nmax = nmax if nmax > (n-a)-a else (n-a)-a
                b = b if nmax > (n-a)-a else (n-a)
    print(str(n) + "=" + str(n-b) + "+" + str(b))