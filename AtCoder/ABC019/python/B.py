s = raw_input()

cnt = 0
pre = s[0]
run_length = []
for i in range(1,len(s)):
    cnt+=1
    if pre != s[i]:
        run_length.append((pre,cnt))
        cnt=0
    if i+1 == len(s):
        run_length.append((s[i],cnt+1))

    pre = s[i]

ans = ""
for c,val in run_length:
    ans += c + str(val)

print ans

