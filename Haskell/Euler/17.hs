to20 = [0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8]

tens = [6, 6, 5, 5, 5, 7, 6, 6]

sign n | n > 0     =  1
       | n < 0     = -1
	   | otherwise =  0

count n | n < 20 = to20 !! n
        | n < 100 = (tens !! (div n 10 - 2)) + (to20 !! (mod n 10))
	    | n < 1000 = (to20 !! (div n 100)) + 7 + (3 * (sign $ count $ mod n 100)) + (count (mod n 100))
	    | n == 1000 = 3 + 8

list n = [x | i <- [1..n], let x = count i]

ans  = sum $ list 1000
