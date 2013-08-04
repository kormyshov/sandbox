list = [x | a <- [1..1000000], let x = len a]

len 1 = 1
len a | even a = 1 + len (div a 2)
	  | otherwise = 1 + len (3 * a + 1)

maxind [] mx res ind = res
maxind (x:xs) mx res ind | x > mx = maxind xs x ind (ind+1)
                         | otherwise = maxind xs mx res (ind+1)

ans = maxind list 0 0 1
