ary = gets()
ary = ary.split()

a1 = ary[0].to_i
a2 = ary[1].to_i
b1 = ary[2].to_i
b2 = ary[3].to_i
c1 = ary[4].to_i
c2 = ary[5].to_i

x1 = b1-a1
x2 = b2-a2
y1 = c1-a1
y2 = c2-a2

ans = (x1*y2 - x2*y1)/2.0

if ans < 0.0
	ans *=(-1)
end

puts ans
	
