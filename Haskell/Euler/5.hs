mylcm [] = 1
mylcm (x:xs) = lcm x (mylcm xs)

list = [1..20]

ans = mylcm list
