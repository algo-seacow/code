n = int(input())
a = list(map(int, input().split()))

ans = 0

if a[0] == 0:
    ans += a[1]

if a[-1] == 0:
    ans += a[-2]

for i in range(1, n - 1):
    if a[i] == 0:
        ans += min(a[i - 1], a[i + 1])

print(ans)
