main :: IO()
main = do
    print (primesProd 12) 
    print (primesProd 1200)

isPrime :: Int -> Bool
isPrime n = [a | a <- [1..n], mod n a == 0] == [1, n]

primesProd :: Int -> Int
primesProd 1 = 1
primesProd x = helper 2 (fromIntegral x)
    where   
        helper res c
            | x < 0 = error "Negative number"
            | (res >= round (sqrt c)) && isPrime res = res
            | (res >= round (sqrt c)) && not(isPrime res) = 1
            | (res < round (sqrt c)) && isPrime res = res * helper (res + 1) c
            | otherwise = helper (res + 1) c