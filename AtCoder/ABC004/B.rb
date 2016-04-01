a = Array.new(4) 

for i in 0..3 do
    a[i] = gets.split(" ")
end

for i in 0..3 do
    for j in 0..3 do
        print a[3-i][3-j]
        if j == 3
            print "\n"
        else
            print " "
        end
    end
end

