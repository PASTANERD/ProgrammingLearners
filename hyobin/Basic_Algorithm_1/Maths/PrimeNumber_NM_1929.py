N , M = map(int, input().split())

count = [False for _ in range(M+1)]

for i in range(2,M+1):
    if count[i]==False :
        if i >= N :
            print(i)
        for j in range(i*2, M+1,i):
            count[j] = True