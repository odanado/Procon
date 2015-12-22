

for i in 160..230 do
    a = `find ./ -name "*#{i}*"`.split("\n")
    if a.length != 0
        system("mkdir Round0#{i}")
        system("mv *#{i}* ./Round0#{i}/")
    end

end
