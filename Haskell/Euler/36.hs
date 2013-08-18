list = [x | x <- [1..999999], rev10 x 0 == x, rev2 x 0 == x]

rev10 0 s = s
rev10 n s = rev10 (div n 10) (10*s + (mod n 10))

rev2 0 s = s
rev2 n s = rev2 (div n 2) (2*s + (mod n 2))

ans = sum list
