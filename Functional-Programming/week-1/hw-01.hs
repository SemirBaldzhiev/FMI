main :: IO()
main = do
    print  (isEvenIf 2)
    print (sumCubes 2 3)
    print (sumCubesWithoutPowOperator 2 3)
    print (averageSum 2 5)
    print (myGcd 10 15)
    print (isLeapYear 2020)
    print (isLeapYear 1988)
    print (isLeapYear 2023)
    print (isLeapYear 1700)
    print (canCarry 5 15 3)
    print (canCarry 51 34.75 19.852)
    print (growingPlant 5 2 6)


-- task 1
isEvenIf :: Int -> Bool
isEvenIf n = mod n 2 == 0

-- task 2
sumCubes :: Int -> Int -> Int 
sumCubes a b = a^3 + b^3

sumCubesWithoutPowOperator :: Int -> Int -> Int 
sumCubesWithoutPowOperator a b = a*a*a + b*b*b

-- task 3
averageSum :: Int -> Int -> Double 
averageSum a b = fromIntegral (a^2 + b^2) / 2

-- task 4
myGcd :: Int -> Int -> Int 
myGcd a 0 = a
myGcd 0 b = b
myGcd a b = if (b == 0) then a else myGcd b (mod a b) 

-- task 5
isLeapYear :: Int -> Bool 
isLeapYear y = (mod y 400 == 0 || mod y 4 == 0) && (mod y 100 /= 0)

-- task 6
canCarry :: Double -> Double -> Double -> Bool
canCarry c k w = c * w <= k

-- task 7
growingPlant :: Int -> Int -> Int -> Int 
growingPlant upSpeed downSpeed level = helper 0 upSpeed downSpeed level

helper :: Int -> Int -> Int -> Int -> Int
helper d us ds l = if l <= 0 then d else helper (d + 1) us ds (l - us + ds)      
