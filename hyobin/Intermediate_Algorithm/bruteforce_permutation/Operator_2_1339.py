from sys import stdin
def go(num, plus, sub, mul, div, i=1) :
    global min_, max_
    if i == N :
        if min_ > num :
            min_ = num
        if max_ < num :
            max_ = num  
        return True
    
    next = numbers[i]
    if plus >0 : 
        go(num+next, plus-1, sub, mul, div, i+1)
    if sub >0  : 
        go(num-next, plus, sub-1, mul, div, i+1)
    if mul >0 : 
        go(num*next, plus, sub, mul-1, div, i+1)
    if div >0 : 
        go(int(num/next), plus, sub, mul, div-1, i+1)

N = int(stdin.readline())
numbers = list(map(int, stdin.readline().split()))
plus, sub, mul, div = list(map(int, stdin.readline().split()))

min_ = (10 ** 9) +1
max_ = min_*-1
go(numbers[0], plus, sub, mul, div)

print(max_)
print(min_)





