n, X = map(int, raw_input().split())
a = map(int, raw_input().split())
ans = 0

for i in range(n):
    if ((X>>i) & 1) == 1:
        ans += a[i]

print ans
