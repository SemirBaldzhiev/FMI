main :: IO()
main = do
    print (findSmallest  [2, 5, 3, 7, 8, 1, 9]) -- [-1, 2, 2, 3, 7, -1, 1]


findSmallest :: (Num a, Ord a) => [a] -> [a]
findSmallest (x:y:xs) = helper [-1] (x:y:xs)
    where 
        helper res (z:t:zs)
            |z < t drop 1 xs  

 