from itertools import permutations
N = int(input())
num = list(map(int, input().split()))
operator = list(map(int,input().split()))
ops = ['+','-','*','/']

op = []
for i in range(4) :
    if(operator[i] != 0) :
        op.extend([ops[i]]*operator[i])

_min = 1000000001
_max = -1000000001
for perm in permutations(op, N-1) :
    n = num[0]
    for i in range(N-1) : 
        if(perm[i] == '+') : 
            n = n + num[i+1]
        if(perm[i] == '-') : 
            n = n - num[i+1]
        if(perm[i] == '*') : 
            n = n * num[i+1]
        if(perm[i] == '/') : 
            if(n < 0) :
                n = ((n*-1) // num[i+1])*-1
            else :
                n = n // num[i+1]
    _min = min(_min, n) 
    _max = max(_max, n)

print(_max)
print(_min)

    


