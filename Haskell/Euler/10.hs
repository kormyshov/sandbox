minus [] _ = []
minus (x:xs) [] = x : xs
minus (x:xs) (y:ys) | x == y = minus xs ys
                    | x > y = minus (x:xs) ys
					| x < y = x : minus xs (y:ys)

primesTo m  =  2 : eratos [3,5..m] where
   eratos (x : xs) | x*x>m = x : xs
                   | True  = x : eratos (minus xs [x*x, x*x+2*x..m])

list = primesTo 2000000

ans = sum list
