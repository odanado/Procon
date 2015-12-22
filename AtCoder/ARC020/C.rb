n = gets.to_i
b = 0
str = ""
for i in 1..n do
    tmp=gets.to_s
    a=tmp.split(" ")[0].to_s
    l=tmp.split(" ")[1].to_i
    for j in 1..l do
        str+=a
    end
end
b=gets.to_i

puts str.to_i % b

