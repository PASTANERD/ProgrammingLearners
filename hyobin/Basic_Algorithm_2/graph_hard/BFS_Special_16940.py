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
check[1] = True
# print(edge)
# print(bfs)
# print()

while(i<N) :
    x = bfs[i]
    count = 0
    # print("x : " , x)
    for y in edge[x] :
        if check[y] == False :
            count = count +1
    # print(" count : " , count)
    for y in bfs[t+1:t+1+count] :
        # print("y : " , y)
        if y not in edge[x] :
            # print("없음")
            answer = False
        check[y] = True
    i = i+1
    t = t+count
    # print()

if(answer) :
    print(1)
else :
    print(0)