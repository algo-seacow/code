from random import *
from string import *

n = randint(50000 - 10000, 50000)

s = []

alpha = "abcdefghijklmnopqrstuvwxyz"

for c1 in alpha:
    for c2 in alpha:
        for i in range(1,100 + 1):
            for j in range(1,100 + 1):
                if (2 * i + j <= 100 and c1 != c2):
                    s.append( c1 * i + c2 * j + c1 * i)

def no():
    aa = 'a' * 40
    for c1 in alpha:
        s.append(c1)
        s.append(aa + c1 + aa)
        for c2 in alpha:
            s.append(c1 + c2)
            s.append(aa + c1 + c2 + aa)
            for c3 in alpha:
                s.append(c1 + c2 + c3)
                s.append(aa + c1 + c2 + c3 + aa)
                for c4 in alpha:
                    s.append(c1 + c2 + c3 +c4)
                    s.append(aa + c1 + c2 + c3 + c4 + aa)


n = min(n, len(s))
print(n)

shuffle(s)
print(*s[0:n], sep='\n')

assert(len(s) >=n)
