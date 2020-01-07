"""
첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.

4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0

0

6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0

2
"""
import numpy as np
import pandas as pd
from itertools import combinations

N = int(input())
score = []
answer = 100
team_list = []

def get_score(comb) :
    score1 = 0
    for c in combinations(comb,2) :
        i, j = map(int,c)
        score1 = score1 + team.iloc[i-1,j-1]
    return score1

for i in range(N) :
    team_list.append(list(map(int, input().split())))
team = pd.DataFrame(np.array(team_list))
team = team.transpose() + team             # (1,0) + (0,1)

comb = []
for c in combinations(list(range(1,N+1)), int(N/2)) :
    comb.append(c)

for n in range(int(len(comb)/2)) :
    score1 = get_score(comb[n])
    score2 = get_score(comb[::-1][n])
    score = abs(score1-score2)
    if(answer > score) : 
        answer = score

print(answer)


