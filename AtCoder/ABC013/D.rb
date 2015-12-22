a = gets.split(" ")
$n = a[0].to_i
$m = a[1].to_i
$d = a[2].to_i
a = gets.split(" ")
$a = a.collect {|e| e.to_i}

$amida = (1..$n).to_a

$a.each do |e|
    $amida[e-1],$amida[e] = $amida[e],$amida[e-1]
end

cnt = 0
i = 1
$amida.each {|item|
    cnt = cnt + 1 if item == i
    i = i + 1
}
a = $n - cnt

$d %= a
$d = $d - 1

$d.times do
    $a.each do |e|
        $amida[e-1],$amida[e] = $amida[e],$amida[e-1]
    end
end

(1..$n).collect {|e| puts $amida.index(e)+1}
