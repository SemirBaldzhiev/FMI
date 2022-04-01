import Distribution.Simple.Utils (xargs)
main::IO()
main = do
    print (divisors 1024)
    print (isTriangular ([[1,2,3],
                          [1,1,1],
                          [0,0,1]]))
    print (nDerive (\ x -> 4*x*x) 1 1e-3 2)  
    print ((repeated (* 2) 3) 5)                  
    


divisors :: Integer -> [Integer]
divisors x = [d | d <- [1..x-1], mod x d == 0]


conatainsZeroes:: [Int] -> Bool
conatainsZeroes [] = True
conatainsZeroes (x:xs) = x == 0 && conatainsZeroes xs

isTriangular :: [[Int]] -> Bool
isTriangular matrix 
                | matrix == [] = True
                | conatainsZeroes (tail (map head matrix)) == True = isTriangular (tail (map tail matrix)) 
                | otherwise = False


myIdentity :: a -> a
myIdentity x = x

myCompose :: (a -> b) -> (c -> a) -> (c -> b)
myCompose f g = \ x -> f (g x)

--myNegate :: (a -> Bool) -> (a -> Bool)
--myNegate p = \ x -> not p x 
--myNegate p = not . p

myCurry :: (a -> b -> c -> d) -> a -> (b -> c -> d)
myCurry f x = f x

difference  :: (Double -> Double) -> Double -> Double -> Double  
difference f a b = (f b) - (f a)

derive :: (Double -> Double) -> Double -> (Double -> Double)
derive f eps = \ x -> (f (x + eps) - (f x))


secondDerive :: (Double -> Double) -> Double -> (Double -> Double)
secondDerive f eps = derive (derive f eps) eps

nDerive :: (Double -> Double) -> Int ->  Double -> (Double -> Double)
nDerive f 0 _ = f
nDerive f n eps = derive (nDerive f (n - 1) eps) eps


repeated :: (a -> a) -> Int -> (a -> a)
repeated f 1 = f
repeated f n =  f . (repeated f (n - 1))  