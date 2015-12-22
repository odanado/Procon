N = input()
a = map(int, raw_input().split(" "))

ans = set()

def cnv(n):
    while n % 2 == 0:
        n /= 2

    return n


for elem in a:
    ans.add(cnv(elem))

print len(ans)

