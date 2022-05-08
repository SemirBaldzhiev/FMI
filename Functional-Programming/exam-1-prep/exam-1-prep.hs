main::IO()
main = do
    print (checkSequence [2,9,15]) 
    print (checkSequence [11,14,20,27,31]) 
    print (checkSequence [11,14,28,27,31]) 
    print (checkSequence [11,14,14,29,31]) 
    print (removeNb 26)
    print (removeNb 100)
    print (removeNb 101)
    print (line (1,1) (1,1) 3)
    print (onDiag (5.5, 5.5))
    print (onDiag (0.5, 0))
-- task-1
checkSequence :: [Int] -> Bool
checkSequence [x] = True
checkSequence [] = True
checkSequence (x:y:xs) = x < y && div x y == 0 && checkSequence (y:xs)

-- tsak-2
removeNb :: Int -> [(Int, Int)]
removeNb n = [(a,b) | a <- [1..n], b <- [1..n], a < n && b < n && a * b == sum [1..n] - a - b] 

-- task-3

type Point = (Double, Double)

diagonal = line (0, 0) (1, 1)

onDiag = liesOn diagonal

line :: Point -> Point -> (Double -> Double)
line a b = \x -> snd a + (x - fst a) * (snd b - snd a) / (fst b - fst a)

liesOn :: (Double -> Double) -> (Point -> Bool)
liesOn f = \(x, y) -> y == f x
