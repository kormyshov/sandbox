list = [x | x <- [1..999], (mod x 3)*(mod x 5) == 0]

ans  = sum list
