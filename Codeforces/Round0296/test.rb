c1 = (0...8).map{ ('a'..'z').to_a[rand(26)] }.join
c2 = (0...8).map{ ('a'..'z').to_a[rand(26)] }.join
puts c1.length
puts c1
puts c2
puts `echo "#{c1.length} #{c1} #{c2}" | ./B1.exe`
puts `echo "#{c1.length} #{c1} #{c2}" | ./B2.exe`

