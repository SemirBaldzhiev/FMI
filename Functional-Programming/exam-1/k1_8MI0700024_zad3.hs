import Data.List

main :: IO()
main = do
    print (maxChain [(3, 4), (5, 6), (7, 8)])
    print (maxChain [(9, 14), (3, 5), (4, 7)])

allPermutations :: [(Int, Int)] -> [[(Int, Int)]]
allPermutations xs = permutations xs

countChainOnePermutation :: [(Int, Int)] -> Int 
countChainOnePermutation permut = helper permut 1
    where 
        helper [(_, _)] c  = c
        helper permut c = if snd (head permut) < fst (head (tail permut)) then helper (tail permut) (c + 1) else helper (tail permut) c

countChainAllPermutations :: [[(Int, Int)]] -> [Int]
countChainAllPermutations permuts = helper [] permuts
    where 
        helper res permuts = if length res == length permuts then res else helper (res++[countChainOnePermutation (head permuts)]) (tail permuts) 

maxChain :: [(Int, Int)] -> Int 
maxChain xs = maximum (countChainAllPermutations (allPermutations xs))