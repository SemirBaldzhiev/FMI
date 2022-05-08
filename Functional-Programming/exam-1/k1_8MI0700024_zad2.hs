import Data.List
main :: IO()
main = do
    print ((pad [[1, 2, 3, 4], [4, 5, 6, 7]] 99))

addMiddle ::  [[a]] -> a -> [[a]]
addMiddle [] elem = []
addMiddle xs elem = ((elem:(head xs))++[elem]):addMiddle (tail xs) elem

pad :: [[a]] -> (a -> [[a]])
pad xs = \x -> ((replicate (length (head xs) + 2) x):(addMiddle xs x))++[(replicate (length (head xs) + 2) x)]


