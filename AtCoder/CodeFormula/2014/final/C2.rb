line = gets.to_s.chomp!
ary = line.split(" ")
ans = Array.new


ary.each {|item|
if item.include?("@")
t = item.split("@")
 for i in 1...t.length
 ans<<t[i]
 end
end
}
ans.sort!
ans.uniq!
ans.each{|item|
puts item if item != ""
}
puts "" if ans.length == 0
