list = [ [x,y] | x <- [1..100], y <- [1..x], cnk x y > 1000000]

cnk n k = div (product [k+1 .. n]) (product [1 .. n-k])

ans = length list
