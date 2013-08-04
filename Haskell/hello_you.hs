evenSum [] = 0
evenSum (x:xs) = (if even x then x else 0) + evenSum xs
