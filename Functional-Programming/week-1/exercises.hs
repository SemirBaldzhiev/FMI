main :: IO()
main = do
    print $ minIf 5 6
    print $ minGuard 5 6
    print $ minBuiltIn 5 6
    print $ lastDigit 123
    print $ quotient 24 4
    print $ wholeDiv 24 5

minIf :: Int -> Int -> Int
minIf x y = if x > y then y else x

minGuard :: Int -> Int -> Int
minGuard x y
 | x > y = y
 | otherwise = x -- x <= y


minBuiltIn :: Int -> Int -> Int
minBuiltIn x y = min x y -- minBuiltIn = min

lastDigit :: Int -> Int
lastDigit n = mod n 10

quotient :: Int -> Int -> Int 
quotient x y = div x y

wholeDiv :: Int -> Int -> Double 
wholeDiv x y = fromIntegral x / fromIntegral y 