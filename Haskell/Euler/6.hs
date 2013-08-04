list1 = [1..100]
list2 = [x*x | x <- [1..100]]

ans = (sum list1)*(sum list1) - sum list2
