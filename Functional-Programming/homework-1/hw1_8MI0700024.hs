main :: IO()
main = do
   -- task 1 outputs
   print (sumCountsIter 1 1)      -- ➝ 1
   print (sumCountsIter 5123 1)   -- ➝ 19
   print (sumCountsIter 1234 8)   -- ➝ 10
   print (sumCountsIter 5555 5)   -- ➝ 10
   print (sumCountsIter 65432 6)  -- ➝ 11
   print (sumCountsIter 70000 1)  -- ➝ 11
   print (sumCountsIter 123321 1) -- ➝ 29
   -- print (sumCountsIter 123321 (-1)) -- ➝ Error!
   --task 2 outputs
   print (maxRotation 56789)      -- ➝ 68957
   print (maxRotation 12490)      -- ➝ 29140
   print (maxRotation 12345)      -- ➝ 24513
   -- print (maxRotation (-122))  -- ➝ Error! 


-- task 1

-- This function retrun how many times given number in range [1...9] is occur in one natural number
countOccurences :: Int -> Int -> Int 
countOccurences 0 0 = 1
countOccurences d n = helper 0 n
    where
        helper c n
            |n == 0 = c
            |mod n 10 == d = helper (c + 1) (div n 10)
            |otherwise = helper c (div n 10)

-- Counts how many times given number is occur in range of natural numbers
-- This function invoke function above for every natural number in the range
countOccurencesInRange :: Int -> Int -> Int 
countOccurencesInRange x d = helper x 0 
   where 
      helper x c
         | x < 0 = error "Number should be natural" 
         | d < 0 || d >= 10 = error "Number should be in range [1...9]!"
         | x == 0 = c
         | otherwise = helper (x - 1) (c + countOccurences d x)


-- Sum of the digits of count occurrences
sumDigits :: Int -> Int 
sumDigits n = if n < 10 then n else (mod n 10) + sumDigits (div n 10)

-- Main function which invoke other functions to find the sum
sumCountsIter :: Int -> Int -> Int
sumCountsIter x d =  sumDigits (countOccurencesInRange x d)

--task 2

countDigits :: Int -> Int
countDigits n = if n < 10 then 1 else 1 + countDigits (div n 10)

-- One rotation with count of fixed digits. Where "i" is current count of fixed digits in the number
rotation :: Int -> Int -> Int
rotation n i = (n * 10 + (mod (div (n*10) (10^((countDigits n) - i))) 10)) - (div (n*10) (10^((countDigits n) - i)) * 10^((countDigits n) - i)) + (div (n) (10^((countDigits n) - i)) * 10^((countDigits n) - i))

-- Max rotation of all rotations
maxRotation :: Int -> Int
maxRotation n = helper n 0 ((countDigits n) - 1) 0
   where 
      helper n max count i
         | n <= 0 = error "Number should be greater than 0!"
         | countDigits n < count = max
         | count == 0 = max
         | n > max = helper (rotation n i) n (count - 1) (i + 1)
         | otherwise =  helper (rotation n i) max (count - 1) (i + 1)