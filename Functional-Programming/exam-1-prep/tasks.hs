main::IO()
main = do
    print (isInteresting 410)

sumDigits :: Int -> Int 
sumDigits 0 = 0
sumDigits n = mod n 10 + sumDigits (div n 10)

isInteresting :: Int -> Bool
isInteresting n = mod n (sumDigits n) == 0



