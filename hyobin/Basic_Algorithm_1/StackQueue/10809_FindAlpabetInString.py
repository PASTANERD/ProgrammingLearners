s = input()
a = ord('a')
z = ord('z')

for i in range(a,z+1) :
    if chr(i) in s :
        print(s.index(chr(i)))
    else :
        print(-1)