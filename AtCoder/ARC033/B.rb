n1,n2 = gets.split(" ")

ary1 = gets.split(" ")
ary2 = gets.split(" ")


puts 1.0*(ary1&ary2).size / (ary1+ary2).uniq.size
