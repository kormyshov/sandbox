gen :: Integer -> Integer -> [Integer]
gen 0 _ = []
gen a b = gena a b ++ gen (a-1) b

gena :: Integer -> Integer -> [Integer]
gena a 0 = []
gena a b = (a ^ b) : gena a (b-1)

getsum 0 = 0
getsum a = (a `mod` 10) + getsum (a `div` 10)

ans = maximum $ map getsum (gen 99 99)
