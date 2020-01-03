from itertools import combinations
vowels = ['a', 'e', 'i', 'o', 'u']
L, C = map(int, input().split())
for comb in combinations(sorted(map(str, input().split())), L) :
    vowels_count = sum(x in comb for x in vowels)
    if(vowels_count >= 1 and vowels_count <= L-2) :
        print("".join(map(str,comb)))
