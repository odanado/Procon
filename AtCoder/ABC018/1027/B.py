s = raw_input()
n = input()

for i in range(n):
    l,r = map(int,raw_input().split())
    l-=1
    # s = s[:l] + s[r:l:-1] + s[r:-1]
    s = s[:l] + s[l:r][::-1] + s[r:]

print s
