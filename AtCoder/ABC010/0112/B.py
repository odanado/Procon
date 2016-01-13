n = input()
a = map(int, raw_input().split())
ans = 0
for i in range(n):
    a[i]-=1
    t = a[i] % 6
    ans += t
    if t > 1:
        ans -= 2

print ans
