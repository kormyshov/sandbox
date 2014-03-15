import Data.List

gen 1 _ = []
gen a b = gena a b ++ gen (a-1) b

gena a 1 = []
gena a b = (a ** b) : gena a (b-1)

uniq [] = 0
uniq (x:xs) | xs == [] = 1
            | x == (head xs) = uniq xs
			| otherwise = 1 + uniq xs

ans = uniq $ sort $ gen 100 100
