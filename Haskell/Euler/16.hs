sumdigit 0 = 0
sumdigit n = (mod n 10) + sumdigit (div n 10)

ans = sumdigit (2^1000)
