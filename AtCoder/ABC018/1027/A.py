a = []
a.append(input())
a.append(input())
a.append(input())

b = sorted(a)
b.reverse()

for e in a:
    print b.index(e) + 1

