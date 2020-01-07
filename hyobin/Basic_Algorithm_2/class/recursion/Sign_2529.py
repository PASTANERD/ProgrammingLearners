"""
여러분은 제시된 부등호 관계를 만족하는 k+1 자리의 
최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력해야 한다. 
단 아래 예(1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 
모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다. 

2
< > 

897
021
"""

min_ = "10000000000"
max_ = "-1"
k = int(input())
sign = input().split()

def go(i, num, sum_) :
    global min_, max_

    if(num<0 or num>9):
        return
    if(str(num) in list(sum_)[:-1]) :
        return
    if(i==k) :
        if(int(min_) > int(sum_)) :
            min_ = sum_
        if(int(max_) < int(sum_)) :
            max_ = sum_
        return
    
    if(sign[i] == "<") :
        for j in range(1, 10) :     #num+1 ~ 9 
            go(i+1, num+j, sum_ + str(num+j))
    if(sign[i] == ">") :
        for j in range(1, 10) :         # 0 ~ num-1
            go(i+1, num-j, sum_ + str(num-j))


for i in range(10):
    go(0,i,str(i))

print(max_ )
print(min_ )





