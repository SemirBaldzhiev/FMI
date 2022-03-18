main::IO()
main = do
    print (len [1, 2, 3])
    print (len ['c', 'a', 'd', 'n'])
    print (sum [1, 2, 3, 4])
    print (contains 2 [1,3,2,3])
    print (contains 5 [1,3,2,3])
    print (primeNumsInRange 1 20)
    print (isPrime 4)
    print (removeAll 3 [2,3,4,2,4,2,3,5,3])
    print (removeFirst 3 [2,3,4,2,4,2,3,5,3])
    print (incrementAllBy [1,2,3,4] 1) 
    print (incrementAllBy [1,2,3,4] 2) 

-- task 1
len :: [t] -> Int
len [] = 0
len (x:xs) = 1 + len xs

-- task 4
sumList :: Num t => [t] -> t 
sumList [] = 0
sumList (x:xs) = x + (sumList xs)

-- task 3
contains :: Eq t => t -> [t] -> Bool 
contains el list = [x | x <- list, x == el] /= []

-- task 4
isPrime :: Int -> Bool 
isPrime n = [x | x <- [2..n], mod n x == 0] == [n]

primeNumsInRange :: Int -> Int -> [Int]
primeNumsInRange a b = [x | x <- [a..b], isPrime x]

-- task 5 
removeFirst :: Eq t => t -> [t] -> [t]
removeFirst d list = if head list == d then tail list else head list:removeFirst d (tail list)

-- task 6
removeAll :: Eq t => t -> [t] -> [t]
removeAll x list = [d | d <- list, d /= x]

-- task 7
incrementAllBy :: [Int] -> Int -> [Int]
incrementAllBy list d = map (d+) list