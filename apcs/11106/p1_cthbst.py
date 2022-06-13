a, b, c = map(int, input().split())

if a < b:
    a, b = b, a
if a < c:
    a, c = c, a
if b < c:
    b, c = c, b

P = 1
if a == b:
    P += 1
if b == c:
    P += 1
print(P, end='')

print(' ', a, end='', sep='')
if a != b:
    print(' ', b, end='', sep='')
if b != c:
    print(' ', c, end='', sep='')
