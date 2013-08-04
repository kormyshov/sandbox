fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

list [] = []
list (x:xs) | x <= 4000000 = x : list xs
            | otherwise = []

ans = sum (filter even (list fibs))
