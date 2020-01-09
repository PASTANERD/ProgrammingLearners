N = int(input())
edge = [[] for _ in range(N+1)]
check = [False] * (N+1)
for _ in range(N-1):
    u, v = map(int, input().split())
    edge[u].append(v)
    edge[v].append(u)
bfs = list(map(int,input().split()))

t = 0
i = 0
answer = True
check[bfs[i]] = True

while(i<N) :
    x = bfs[i]
    count = 0
    for y in edge[x] :
        if check[y] == False :
            count = count +1
    for y in bfs[t+1:t+1+count] :
        if y not in edge[x] :
            answer = False
        check[y] = True
    i = i+1
    t = t+count

if(answer) :
    print(1)
else :
    print(0)