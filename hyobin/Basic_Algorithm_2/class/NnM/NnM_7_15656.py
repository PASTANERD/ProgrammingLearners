# -*- coding: utf-8 -*- 
# 중복 순열
from itertools import product
N, M = map(int, input().split())
for pair in product(sorted(map(int, input().split())), repeat = M) :
    print(" ".join(map(str,pair)))