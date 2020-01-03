"""
각 줄에 하나씩, 사전식으로 가능성 있는 암호를 모두 출력한다.

4 6
a t c i s w

acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw
"""

from itertools import combinations
vowels = ['a', 'e', 'i', 'o', 'u']
L, C = map(int, input().split())
for comb in combinations(sorted(map(str, input().split())), L) :
    vowels_count = sum(x in comb for x in vowels)
    if(vowels_count >= 1 and vowels_count <= L-2) :
        print("".join(map(str,comb)))
