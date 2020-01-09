from itertools import combinations
while(True) :
    s = input()
    if(s == "0") :
        break
    num = s.split()[1:]

    for comb in combinations(num, 6) :
        print(" ".join(comb))
    print()
    
