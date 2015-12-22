t = gets.split(" ")
a = t[0].to_i
b = t[1].to_i

ap = gets.split(" ")
aq = gets.split(" ")

ans = Array.new(10,"x")
ap.each {|i|
  ans[i.to_i-1] = "."
}
aq.each {|i|
  ans[i.to_i-1] = "o"
}

puts ans[6]+" "+ans[7]+" "+ans[8]+" "+ans[9];
puts " "+ans[3]+" "+ans[4]+" "+ans[5];
puts "  "+ans[1]+" "+ans[2];
puts "   "+ans[0];




