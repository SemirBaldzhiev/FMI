import Data.Array.Base (listArrayST)
main::IO()
main = do
    print (insert 3 [1,2,4,5])
    print (merge [1,2,3,4] [7,8,9,10])
    print (insertionSort [2,6,1,8,3,5])
    -- print ((maximize [(\x -> x*x*x),(\x -> x+1)]) 0.5)
    print (newtonSqrt 612) 



insert :: Int -> [Int] -> [Int]
insert n [] = [n]
insert n (x:xs) = if n < x then n:x:xs else x : insert n xs

merge :: [Int] -> [Int] -> [Int]
merge [] [] = []
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = if x < y then x:merge xs (y:ys) else y:merge (x:xs) ys

insertionSort :: [Int] -> [Int]
insertionSort list = foldr insert [] list


-- maximize :: (Ord a, Num a) => [(a -> a)] -> (a -> a)
-- maximize xs = foldr (\x -> ) id xs

newtonSqrt :: Double -> Double 
newtonSqrt x = helper (x / 10)
    where helper curr = if abs (curr - next) < 0.0001 then next
                     else helper next
                     where next = curr - (curr ^ 2 - x) / ( curr * 2)