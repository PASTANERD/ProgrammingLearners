from itertools import permutations
N = int(input())
alphabet = []
frequency = []
for n in range(N) : 
    i = 1
    for s in input()[::-1] :
        if s not in alphabet :
            alphabet.append(s)
        idx = alphabet.index(s)
        if(len(frequency) <= idx ) :
            frequency.append(i)
        else :
            frequency[idx] += i
        i = i*10

max = 0
for per in permutations([0,1,2,3,4,5,6,7,8,9],len(alphabet)) :
    n=0
    for i in range(len(alphabet)) : 
        n += per[i]*frequency[i] 
    if(max < n) :
        max = n
print(max)




