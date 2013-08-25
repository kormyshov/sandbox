import Data.List

list = [x | x <- [12..28123], sumDiv x > x + x]

sumDiv n = sum ([y | x <- [1..(floor $ sqrt $ fromIntegral n)], mod n x == 0, let t = div n x, let y = sumDiv_y x t ])

sumDiv_y a b | a == b = a
             | otherwise = a + b

listSum _ [] = []
listSum [] _ = []
listSum (x:xs) (y:ys) = (tmp x (y:ys)) ++ (listSum xs xs)

tmp x [] = []
tmp x (y:ys) | x+y>28123 = []
             | otherwise = (x+y):(tmp x ys)

list2 = nub $ sort $ listSum list list

ans = sum [x | x <- [1..28123], notElem x list2]
