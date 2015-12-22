N, M = map(int, raw_input().split())
dp = [[100000000 for i in range(301)] for j in range(301)]

for i in range(301):
    dp[i][i] = 0

for i in range(M):
    a, b, t = map(int, raw_input().split())
    dp[a-1][b-1] = t
    dp[b-1][a-1] = t

for k in range(N):
    for i in range(N):
        for j in range(N):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

ans = 100000000
for i in range(N):
    t = 0
    for j in range(N):
        t = max(t, dp[i][j])
    ans = min(t, ans)

print ans
