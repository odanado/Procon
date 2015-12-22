def f(n)
    res = (n*n/4).floor

    return res

end

input = gets

r = input.split(" ")[0].to_i
g = input.split(" ")[1].to_i
b = input.split(" ")[2].to_i

ans = 0
ans = f(r)+f(g)+f(b)

p ans

