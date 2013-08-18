list = [x | x <- [10..99999], sum_dig_fact x == x]

sum_dig_fact 0 = 0
sum_dig_fact n = (fact (mod n 10)) + sum_dig_fact (div n 10)

fact 0 = 1
fact n = product [1..n]

ans = sum list
