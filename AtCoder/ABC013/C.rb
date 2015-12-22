a = gets.split(" ")
$n = a[0].to_i
$h = a[1].to_i
a = gets.split(" ")
$a = a[0].to_i
$b = a[1].to_i
$c = a[2].to_i
$d = a[3].to_i
$e = a[4].to_i
$dp = Array.new(1000).map{Array.new(50,-1)}

INF = 1000000000000000000

def min(a,b)
    a < b ? a : b
end
# i nitime de manpuku j no saisyoka
def func(i,j)
    return 0 if i == $n+1
    return INF if j <= 0
    return $dp[i][j].to_i if !$dp[i][j].nil? and $dp[i][j].to_i != -1
    # puts "#{i},#{j}"
    
    ret = INF

    ret = min(ret,func(i+1,j-$e))
    ret = min(ret,func(i+1,j+$b)+$a)
    ret = min(ret,func(i+1,j+$d)+$c)

    $dp[i][j] = ret
end
def func2(i,j)
    return 0 if i == $n+1
    return INF if j <= 0
    # puts "#{i},#{j}"
    
    ret = INF

    ret = min(ret,func2(i+1,j-$e))
    ret = min(ret,func2(i+1,j+$b)+$a)
    ret = min(ret,func2(i+1,j+$d)+$c)

    ret
end

if $n <= 10
    p func2(0,$h)
else
    p func(0,$h)
end

