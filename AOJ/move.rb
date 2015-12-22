
ary = `ls *.cpp`.split("\n")

ary.each do |file|
    n = file.to_i
    if n < 100
        system("mv #{file} ./Volume00")

    elsif n < 200
        system("mv #{file} ./Volume01")
    elsif n < 300
        system("mv #{file} ./Volume02")
    elsif n < 400
    elsif n < 500
    elsif n < 600
        system("mv #{file} ./Volume05")
    end
end

