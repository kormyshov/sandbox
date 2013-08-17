pow a 0 = 1
pow a b | mod b 2 == 0 = pow (mod (a^2) 10000000000) (div b 2)
	    | otherwise = mod (a * (pow a (b-1))) 10000000000

sum_pow 0 = 0
sum_pow n = pow n n + sum_pow (n-1)

ans = mod (sum_pow 1000) 10000000000
