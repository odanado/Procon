n = gets.to_i
if n==1
  puts"YES"
  exit
end
for i in 0...n do
  if i*i*i == n
    puts "YES"
    exit
  end
end
puts "NO"
