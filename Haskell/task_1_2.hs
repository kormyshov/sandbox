tf :: Integer -> Integer
tf 0 = 0
tf n = n+tf(n-1)

pf :: Integer -> Integer
pf 0 = 0
pf n = tf(n)+pf(n-1)
