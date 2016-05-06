import commands
import random as rng

def make_test():
    f = open("test.txt", "w")
    n = rng.randint(1, 1000)
    k = rng.randint(1, 10000000000)
    f.write("%d %d\n" % (n, k));
    a = [rng.randint(1,100) for i in range(n)]
    f.write(" ".join(map(str, a)) + "\n")
    f.write(" ".join([str(rng.randint(int(1),10)) for i in range(n)]) + "\n")

n = 100000
k = 2000000000
print("%d %d" % (n, k))
for i in range(n):
    print(1)

"""
while True:
    make_test()
    res1 = commands.getoutput('./Hack.out < ./test.txt')
    res2 = commands.getoutput('./a.out < ./test.txt')
    print(res1, res2)
    if res1 != res2:
        break;
"""
