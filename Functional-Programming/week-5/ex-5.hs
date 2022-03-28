main::IO()
main = do
    print (multiplyAllBy [1,2,3,4] 2)
    print (filterSmallerThan [1,2,3,4,5,6,7] 3)
    print (isAscending 1234956)
    print (isImage [2,3,4,5,6] [1,2,3,4,5])
    print (chunksOf 3 [1,2,3,4,5,6,7,8])
    --print (take 2 [1,2,3,4])
     


-- tas 1
multiplyAllBy :: [Int] -> Int -> [Int]
multiplyAllBy list num = [n * num | n <- list]

-- task 2
filterSmallerThan :: [Int] -> Int -> [Int]
filterSmallerThan xs n = [x | x <- xs, x >= n] 

-- task 3
numberToList :: Integer -> [Integer]
numberToList 0 = []
numberToList n = numberToList (div n 10) ++ [mod n 10]

isAscendingList :: [Integer] -> Bool 
isAscendingList [] = True 
isAscendingList [x] = True
isAscendingList (x:y:xs) = x <= y && isAscendingList (y:xs) 

isAscending :: Integer -> Bool
isAscending n = isAscendingList (numberToList n)

-- task 4

isImage :: [Int] -> [Int] -> Bool
isImage [] [] = False
isImage [x] [y] = True
isImage (a:x:as) (b:z:bs) = a - b == x - z && isImage (x:as) (z:bs)


-- task 5
takeChunk :: Int -> [a] -> [a] 
takeChunk _ [] = []
takeChunk 0 (x:xs) = []
takeChunk n (x:xs) = x:(takeChunk (n-1) xs)

removeFirstN ::Int -> [a] -> [a]
removeFirstN _ [] = []
removeFirstN 0 list = list
removeFirstN n (x:xs) = removeFirstN (n - 1) xs

chunksOf :: Int -> [a] -> [[a]]
chunksOf _ [] = []
chunksOf n list = (takeChunk n list):chunksOf n (removeFirstN n list)

-- task 6


