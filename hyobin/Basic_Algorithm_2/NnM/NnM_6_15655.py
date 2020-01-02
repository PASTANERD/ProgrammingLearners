from itertools import combinations
N,M = map(int,input().split())
for pair in combinations(sorted(map(int,input().split())), M) :
    print(" ".join(map(str,pair)))