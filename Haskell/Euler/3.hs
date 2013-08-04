prime n = length [x | x <- [1..(floor $ sqrt $ fromIntegral n)], mod n x == 0] == 1

list n = [x | x <- [1..(floor $ sqrt $ fromIntegral n)], mod n x == 0, prime x]

ans = maximum (list 600851475143)
