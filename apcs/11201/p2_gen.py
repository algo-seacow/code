from random import *
import string

K = randint(1, 20)
R = randint(1, K)
Q = randint(1, 20)

s = ''.join(choice(string.ascii_lowercase) for _ in range(K))

print(K, Q, R)
print(s)
for _ in range(Q):
    v = [ i for i in range(1, K+1) ]
    shuffle(v)
    print(*v)

