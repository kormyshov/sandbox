ans = maximum [x*y | x <- [100..999], y <- [100..999], (show (x*y)) == (reverse $ show (x*y))]
