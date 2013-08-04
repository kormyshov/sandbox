tf :: Integer -> Integer
tf 0 = 0
tf n = n+tf(n-1)
