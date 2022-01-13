from random import *

n = randint(63, 63)
m = randint(1, 1)

print(n, m)
s = [randint(1, 100) for _ in range(n)]
t = [randint(1, 100) for _ in range(n)]
p = [i + 1 for i in range(n)]
shuffle(p)

print(*s)
print(*t)
print(*p)
