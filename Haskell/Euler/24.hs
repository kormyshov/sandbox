ans = perm [0,1,2,3,4,5,6,7,8,9] 999999

perm [] _ = []
perm (x:xs) 0 = x:xs
perm (x:xs) n = (head nl):(perm (tail nl) (mod n (fact $ length xs))) where nl = sw [] (x:xs) n (fact $ length xs)

fact 0 = 1
fact n = product [1..n]

sw [] (y:ys) n f | n<f = (y:ys)
	             | otherwise = sw (y:[]) ys (n-f) f

sw (x:xs) (y:ys) n f | n < f = y:((x:xs) ++ ys)
	                 | otherwise = sw ((x:xs) ++ (y:[])) ys (n-f) f
