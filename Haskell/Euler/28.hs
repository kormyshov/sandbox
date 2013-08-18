arithm 1 = 1
arithm n = 4*(1+5*(n-1)+(4*(n-2)*(n-1))) + arithm (n-1)

ans  = arithm (div (1001+1) 2)
