cnt _ [] = 0
cnt n (x:xs) | n < 0 = 0
             | n == 0 = 1
             | otherwise = (cnt (n-x) (x:xs)) + (cnt n xs)

ans = cnt 200 [1,2,5,10,20,50,100,200]
