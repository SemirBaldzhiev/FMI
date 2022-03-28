main::IO()
main = do
    print (dominates (\x -> x + 1) (\x -> x + 2) [1, 2, 3, 4, 5])
    print (dominates (\x -> x * 3) (\x -> x + 2) [1, 2, 3, 4, 5])


dominates :: (Int -> Int) -> (Int -> Int) -> [Int] -> Bool
dominates f g [] = True
dominates f g (x:xs) = abs (f x) >= abs (g x) && dominates f g xs


