n = input()

imos = [0] * 1000006

for i in range(n):
    a, b = map(int, raw_input().split())
    imos[a] += 1
    imos[b+1] -= 1

for i in range(1,1000006):
    imos[i] += imos[i-1]

print max(imos)

