N = input()
s = 0
for i in range(1,10):
    for j in range(1,10):
        s += i * j

d = s - N
ans = list()
for i in range(1, 10):
    if d % i == 0 and d / i < 10:
        ans.append("%d x %d" % (i, d / i))

for e in ans:
    print e
