from itertools import combinations_with_replacement
N,M = map(int,input().split())
for pair in combinations_with_replacement([i+1 for i in range(N)], M) :
    print(" ".join(map(str,pair)))