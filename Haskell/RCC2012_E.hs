rcce :: Integer -> [[Integer]]
rcce n = [ [d1,d2,d3] | d1 <- [1..n], 
						d2 <- [d1..n], 
						d3 <- [d2..n], 
						length [ x | x <- [1..d1], mod d1 x == 0 ] == 2,
						length [ x | x <- [1..d2], mod d2 x == 0 ] == 2,
						length [ x | x <- [1..d3], mod d3 x == 0 ] == 2,
						mod ((d1+d2)*(d1+d2)-1) d3 == 0,
						mod ((d2+d3)*(d2+d3)-1) d1 == 0,
						mod ((d1+d3)*(d1+d3)-1) d2 == 0 
		 ]
