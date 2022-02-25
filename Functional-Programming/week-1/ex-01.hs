main :: IO()
main = do
    print (myMin 2 9)
    print (isInside 4 1 7)
    print (calcAverage 2 3)
    print (fibRec 3)
    print (fibIter 50)

-- task 1
myMin :: Int -> Int -> Int
myMin a b = if a < b then a else b

-- task 2
isInside :: Int -> Int -> Int -> Bool 
isInside x a b = x >= a && x <= b 

-- task 3
calcAverage :: Double -> Double -> Double 
calcAverage a b = (a^2 + b^2) / 2

-- task 4
fibRec :: Int -> Integer 
fibRec n = if (n <= 1) then 1 else fibRec (n - 2) + fibRec (n - 1)

-- task 5
fibIter :: Int -> Integer
fibIter n = helper 0 1 0 n

helper :: Integer -> Integer -> Int -> Int -> Integer 
helper prev cur i n = if i == n then cur else helper cur (prev + cur) (i + 1) n