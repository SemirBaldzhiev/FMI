import Control.Concurrent (isCurrentThreadBound)
main :: IO()
main = do
    print $ minIf 5 6
    print $ minGuard 5 6
    print $ minBuiltIn 5 6
    print $ lastDigit 123
    print $ quotient 24 4
    print $ wholeDiv 24 5
    print (removeLastDigit 123)
    print (divReal 123.12 43.56)
    print (quotientReal 123.12 43.56)
    print (avgWhole 3 4)
    print (roudTwoDigits 3.123332312)
    print (areNotEqual 4 3)
    print (areNotEqual 4 4)
    print (areNotEqualGuard 3 6)
    print (areNotEqualGuard 3 3)
    print (inside 2 4 8)
    print (inside 2 1 8)
    print (factRec 5)
    print (factIter 12)

-- task 1
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

removeLastDigit :: Int -> Int
removeLastDigit n = div n 10

divReal :: Double -> Double -> Double 
divReal a b = a / b

quotientReal :: Double -> Double -> Int 
quotientReal a b = round (a / b)

avgWhole :: Int -> Int -> Double 
avgWhole a b = (fromIntegral (a + b)) / 2

roudTwoDigits :: Double -> Double 
roudTwoDigits n = fromIntegral (round (n * 100)) / 100

--task 2
areNotEqual :: Int -> Int -> Bool 
areNotEqual a b = a /= b

areNotEqualGuard :: Int -> Int -> Bool 
areNotEqualGuard a b
    | a == b = False 
    | otherwise = True

inside :: Int -> Int -> Int -> Bool 
inside x a b = x >= a && x <= b

-- task 3
factRec :: Integer -> Integer 
factRec n = if n == 0 then 1 else n * factRec (n - 1)

factIter :: Integer -> Integer
factIter n = helper 1 n

helper :: Integer -> Integer -> Integer
helper res n = if n == 0 then res else helper (n * res) (n - 1)
