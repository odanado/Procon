n = gets.to_i

ary2 = Array.new(91)

ary2[0] = [1,2,3,4,5,6]

for j in 1..90 do
    ary = [1,2,3,4,5,6]


    for i in 0..j-1 do
        ary[i%5],ary[i%5+1] = ary[i%5+1],ary[i%5]
    end
    ary2[j] = ary
end

for i in 0..5 do
    print ary2[n%90][i]
end
