def cnv(time,before):
    h = time / 100
    m = time % 100

    if not before and m % 5 != 0:
        m += 5

    m = m - m % 5

    if m == 60:
        m = 0
        h += 1

    return min(1440, h * 60 + m)

N = input()

imos = [0] * (24 * 60 + 2)

for i in range(N):
    s, t = map(int, raw_input().split("-"))
    s = cnv(s,True)
    t = cnv(t,False)
    imos[s+1] += 1
    imos[t+1] -= 1

for i in range(len(imos)):
    if i > 0:
        imos[i] += imos[i-1]

s = []
t = []
for i in range(len(imos) - 1):
    if imos[i] == 0 and imos[i+1] > 0:
        s.append(i)
    if imos[i] > 0 and imos[i+1] == 0:
        t.append(i)

for i in range(len(s)):
    print "%02d%02d-%02d%02d" % (s[i]/60,s[i]%60,t[i]/60,t[i]%60)
