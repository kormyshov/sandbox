sumdigit 0 = 0
sumdigit n = (mod n 10) + sumdigit (div n 10)

fact 1 = 1
fact n = n * fact (n-1)

ans = sumdigit $ fact 100
