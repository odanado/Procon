import math
n = input()
s = 0
cnt = 0
a = map(int, raw_input().split())
for i in range(n):
    s += a[i]
    if a[i] > 0:
        cnt += 1

ans = math.ceil(1.0 * s / cnt)

print int(ans)

