answer = 0
def recur(sum_, i) :
    global answer
    curr_sum = sum_ + num[i]
    # print(sum_, " ", num[i] , " " , curr_sum)
    if(curr_sum == S) :
        answer += 1
    if(i==N-1) :
        return
    recur(curr_sum, i+1)
    recur(sum_, i+1)

N, S = map(int, input().split())
num = list(map(int, input().split()))
recur(0,0)
print(answer)


 