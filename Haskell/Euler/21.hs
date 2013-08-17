list = [y | x <- [0..10000], let y = sum_div x]

sum_div n = sum (1:[y | x <- [2..(floor $ sqrt $ fromIntegral n)], mod n x == 0, let t = div n x, let y = sum_div_y x t ])

sum_div_y a b | a == b = a
              | otherwise = a + b

pair [] _ = []
pair (x:xs) i | (i > x) && (list !! x == i) = (i+x) : pair xs (i+1)
			  | otherwise = pair xs (i+1)

ans = sum $ pair list 0
