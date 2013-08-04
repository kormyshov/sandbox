list = [(div (n*(n+1)) 2) | n <- [1..100000], let x = count (div (n*(n+1)) 2), x > 500]

count a = 2 * length [x | x <- [1..(floor $ sqrt $ fromIntegral a)], mod a x == 0]

ans = minimum list
