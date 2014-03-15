tmp = [x | a <- [1..1000000], let x = reverse $ digits a ]

digits 0 = []
digits a = (a `mod` 10) : digits (a `div` 10)

merge [] = []
merge (x:xs) = x ++ merge xs

d = merge tmp

ans = d !! 0 * d !! 9 * d !! 99 * d !! 999 * d !! 9999 * d !! 99999 * d !! 999999
