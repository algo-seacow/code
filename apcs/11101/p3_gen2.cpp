from random import *
from string import *

n = randint(50000 - 1000, 50000)
print(n)

s = []

alpha = 'qwertyuiopasdfghjklzxcvbnm'

for i in range(n):
    u = ''.join(choice(alpha) for x in range(5))
    v = ''.join(choice(alpha) for x in range(5))
    x = ''.join(choice(alpha) for x in range(10))
    s.append(x)
    s.append(u + x + u)
    s.append(u + x + v)

shuffle(s)
print(*s[0:n], sep='\n')
