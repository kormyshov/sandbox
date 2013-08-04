list = [(a,b,c) | a <- [1..1000], b <- [(a+1)..1000], let c = 1000-a-b, a*a + b*b == c*c]

sol (x:xs) = prod x

prod (a,b,c) = a*b*c

ans = sol list
