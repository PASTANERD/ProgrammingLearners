"""
첫째 줄에 수열의 크기 N이 주어진다. 
N은 10보다 작거나 같은 자연수이다. 
둘째 줄에는 N(N+1)/2 길이의 문자열이 주어진다. 
처음 N개의 문자는 부호 배열의 첫 번째 줄에 해당하고, 
다음 N-1개의 문자는 두 번째 줄에 해당한다. 
마찬가지로 마지막 문자는 N번째 줄에 해당하는 문자다.

첫째 줄에 수열의 원소 N개를 빈 칸을 사이에 두고 출력한다. 
답이 여러 가지 일 경우에는 아무거나 출력하면 된다.

4
-+0++++--+

-2 5 -3 1
"""
from itertools import combinations_with_replacement
N = int(input())
sign = list(input())
comb =  list(combinations_with_replacement([x for x in range(N)],2))
num = [0 for x in range(N)]

def go(idx, num_) :
    num = num_[:]
    sum_ = 0
    ii = comb[idx][1]
    for i in range(comb[idx][0], comb[idx][1]+1) :
        sum_ += num[i]

    print("idx : " , idx, " num : " , num, " sign[idx] : " , sign[idx], " sum_ : ", sum_)
    print("ii : " , ii, " sign[comb.index((ii,ii))] : ", sign[comb.index((ii,ii))])
    if(sign[idx] == "+") : 
        for i in range(1, 21) :
            if( sign[comb.index((ii,ii))]=="+") :     #양수이면
                if(num[ii]+i > 10) :
                    return
                num[ii] = num[ii] + i
            elif( sign[comb.index((ii,ii))]=="-") :     #음수
                if(num[ii]+i < -10) :
                    return
                num[ii] = num[ii] - i
            print(num)
            print("\n")
            go(idx+1, num)

    if(sign[idx] == "-") : 
        for i in range(1, 21) :
            if( sign[comb.index((ii,ii))]=="+") :     #양수이면
                if(num[ii]+i > 10) :
                    return
                num[ii] = num[ii] + i
            elif( sign[comb.index((ii,ii))]=="-") :     #음수
                if(num[ii]+i < -10) :
                    return
                num[ii] = num[ii] - i
            print(num)
            print("\n")
            go(idx+1, num)


    if(sign[idx] == "0") : 
        return

go(0, num)

# ++++++++++

                


            



