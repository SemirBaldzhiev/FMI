main :: IO()
main = do
    print (pow 3 2)
    print (pow 2 5)
    print (pow 2 0)
    print (isPrime 123)
    print (isPrime 17)
    print (isAscending 12342)
    print (isAscending 2)
    print (isAscending 1234)
    print (countOccurences 2 12232)
    print (countOccurences 2 78)
    print (countOccurences 2 2)
    print (countOccurences 3 12232)
    print (isPerfectNumber 28)
    print (sumPrimeDivisors 20)

-- task 1
pow :: Double -> Int -> Double
pow x 0 = 1
pow x n = x * pow x (n - 1)

-- task 2
isPrime :: Int -> Bool 
isPrime n = n > 1 && helper 2
    where
        helper i
            |fromIntegral i >= sqrt(fromIntegral n) = True 
            |mod n i == 0 = False 
            |otherwise = helper (i + 1)

-- task 3
isAscending :: Int -> Bool 
isAscending n
    |n < 10 = True
    |otherwise = mod n 10 >= mod (div n 10) 10 && isAscending (div n 10)


-- task 4
countOccurences :: Int -> Int -> Int 
countOccurences 0 0 = 1
countOccurences d n = helper 0 n
    where
        helper c n
            |n == 0 = c
            |mod n 10 == d = helper (c + 1) (div n 10)
            |otherwise = helper c (div n 10)

--task 5
sumDivs :: Int -> Int 
sumDivs n = helper 1 0
    where 
        helper i r
            | i >= (n - 1) = r
            | mod n i == 0 = helper (i + 1) (r + i)
            | otherwise = helper (i + 1) r

isPerfectNumber :: Int -> Bool 
isPerfectNumber n = sumDivs n == n

-- task 6
sumPrimeDivisors :: Int -> Int 
sumPrimeDivisors n = sum([x | x <- [1..n], mod n x == 0, isPrime x])
