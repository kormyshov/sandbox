minus [] _ = []
minus (x:xs) [] = x : xs
minus (x:xs) (y:ys) | x == y = minus xs ys
                    | x > y = minus (x:xs) ys
					| x < y = x : minus xs (y:ys)

primesTo m  =  2 : eratos [3,5..m] where
   eratos (x : xs) | x*x>m = x : xs
                   | True  = x : eratos (minus xs [x*x, x*x+2*x..m])

list = primesTo 500500

pn [] _ = 0
pn (x:xs) 0 = x
pn (x:xs) n = pn xs (n-1)

ans = pn list 10000
