subset :: [Integer] -> [[Integer]]
subset [] = [[]]
subset (x:xs) = l0 ++ l1
	where
		l0 = subset xs
		l1 = [ x:l | l <- l0 ]
