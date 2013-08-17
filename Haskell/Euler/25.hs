fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

lower_bound (x:xs) n i | x >= n    = i
                       | otherwise = lower_bound xs n (i+1)

ans  = lower_bound fibs (10^999) 0
