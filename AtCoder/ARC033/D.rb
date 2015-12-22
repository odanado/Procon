require 'matrix'
$mod = 1000000007

def pow(a,n)
    res = 1
    while n > 0 do
        res = (res * a) % $mod if n & 1 == 1
        n /= 2
        a *= a
    end

    res
end

def make_a(i,n)
    result = []
    n.times{|j|
        result << pow(i,j)
    }

    result.reverse
end
n = gets.to_i

a = gets.split(" ").collect{|i| i.to_i}
a = Vector.elements(a)
r = []
t = gets.to_i
for i in 0..n
    r << make_a(i,n+1)
end

m = Matrix.rows(r, true)
b = m.inverse * a
ans = 0
for i in 0..n do
    ans += pow(t * b[i],n-i)
    ans %= $mod
    
end
p ans.to_i
