main :: IO()
main = do
    --print t1
    --print (size t1)
    --print (height t1)
    --print (sumTree t1)
    --print (sumLeaves t1)
    --print (sumLeaves t2)
    --print (inorder t1)
    --print (inorder t2)
    --print (getLevel 1 t2)
    print (mirror t2)





data BTree = Empty | Node Int BTree BTree
    deriving Show

t1 :: BTree
t1 = Node 5 (Node 2 Empty 
                    (Node 3 Empty Empty))
            (Node 6 Empty Empty)

t2 :: BTree
t2 = Node 5 (Node 3 Empty Empty)    
                     (Node 4 (Node 5 Empty Empty)    
                                   (Node 7 Empty Empty)) 

size :: BTree -> Int
size Empty = 0
size (Node r ln rn) = 1 + size ln + size rn 

height :: BTree -> Int
height Empty = 0;
height (Node r ln rn) = 1 + max (height ln) (height rn)

sumTree :: BTree -> Int
sumTree Empty = 0;
sumTree (Node r ln rn) = r + sumTree ln + sumTree rn

sumLeaves  :: BTree -> Int
sumLeaves Empty = 0
sumLeaves (Node v Empty Empty) = v;
sumLeaves (Node r ln rn) = sumLeaves ln + sumLeaves rn

inorder :: BTree -> [Int]
inorder Empty = []
inorder (Node r ln rn) = inorder ln ++ [r] ++ inorder rn

getLevel :: Int -> BTree -> [Int]
getLevel _ Empty = []
getLevel 0 (Node v _ _ ) = [v]
getLevel k (Node _ ln rn) =  getLevel (k - 1) ln ++ getLevel (k - 1) rn

average :: BTree -> Double
average t = fromIntegral (sumTree t) / fromIntegral (size t) 

mirror :: BTree -> BTree
mirror Empty = Empty
mirror (Node r lt rt) = Node r (mirror rt) (mirror lt)