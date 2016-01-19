N = input()
A = []
for i in range(N):
    A.append(input())
A = list(set(A))
A[A.index(max(A))] = -1
print max(A)
