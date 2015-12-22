a = gets()

ans=""

for i in 0..a.size-1 do 
	#p a[i]
	if a[i]!='a' && a[i]!='i' && a[i]!='u' && a[i]!='e' && a[i]!='o'
		ans+=a[i];
	end
end
puts ans
