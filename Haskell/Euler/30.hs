list = [x | x <- [10..199999], sm x == x]

sm 0 = 0
sm x = ((mod x 10)^5) + sm (div x 10)

ans = sum list
