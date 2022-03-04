main :: IO()
main = do
    print (myGCD 24 8)
    print (myGCD 17 8)
    print (countDigits 123)
    print (countDigits 123456)
    print (sumDigitsRec 123)
    print (sumDigitsRec 123456)
    print (sumDigitsIter 1234567)
    print (sumDigitsIter 1)
    print (sumDigitsIter 527)
    print (reverseNumber 12)
    print (reverseNumber 12345)
    print (reverseNumber 1)

-- task1
myGCD :: Int -> Int -> Int
myGCD a 0 = a
myGCD a b = myGCD b (mod a b)   

-- task2
countDigits :: Int -> Int 
countDigits n = if n < 10 then 1 else 1 + countDigits (div n 10)

-- task3
sumDigitsRec :: Int -> Int 
sumDigitsRec n = if n < 10 then n else (mod n 10) + sumDigitsRec (div n 10)

-- task4
sumDigitsIter :: Int -> Int 
sumDigitsIter n = helperSum 0 n

helperSum :: Int -> Int -> Int  
helperSum sum n = if n < 10 then sum + n else helperSum (sum + mod n 10) (div n 10)

-- task5
reverseNumber :: Int -> Int 
reverseNumber n = reverseHelper 0 n
    where 
        reverseHelper rev k = 
            if k == 0 then rev else reverseHelper (10 * rev + (mod k 10)) (div k 10)