N = int(input())
sequence = list(map(int, input().split()))

dp_up = [0] * N
dp_down = [0] * N
dp_up[0] = 1
dp_down[0] = 1

for i in range(1, N):
    down_value = 0
    up_value = 0
    for j in range(i):
        if(sequence[i] > sequence[j]):
            down_value = max(dp_down[j], down_value)
    for j in range(N - i, N):
        if(sequence[N - i] > sequence[j]):
            up_value = max(dp_up[j], up_value)
    dp_down[i] = down_value + 1
    dp_up[N - i] = up_value + 1
print(max(list(map(lambda x, y :  x + y, dp_down, dp_up))) - 1)