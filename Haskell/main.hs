main = print [x | x <- [1..n], mod n x == 0] where n <- getInteger
