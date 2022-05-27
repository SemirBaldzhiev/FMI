main :: IO()
main = do
    print (mapTree (\x -> x + 1) t1)
    print (inorder colorTree)


data BTree a = Empty | Node a (BTree a) (BTree a) deriving Show

t1::BTree Int
t1 = Node 5 (Node 2 Empty Empty) (Node 7 Empty Empty)

mapTree :: (a -> b) -> BTree a -> BTree b
mapTree f Empty = Empty
mapTree f (Node v lt rt) = Node (f v) (mapTree f lt) (mapTree f rt)

data Color = Red | Green | Blue deriving (Read, Show, Eq)

colorTree :: BTree Color                                            --            Blue
colorTree = Node Blue (Node Red (Node Green Empty Empty) Empty)     --           /    \
                      (Node Red (Node Red (Node Green Empty Empty) --        Red      Red
                                           (Node Blue Empty Empty))  --        /        /  
                                Empty)

inorder :: BTree Color -> [Color]
inorder Empty = []
inorder (Node v lt rt) = inorder lt ++ (v : inorder rt)


data NTree a = NEmpty | NNode a [NTree a] deriving Show

nTree1 :: NTree Int                               --       1
nTree1 = NNode 1 [(NNode 2 [(NNode 3 [NEmpty]),   --      / \
                            (NNode 4 [NEmpty]),   --     2   6
                            (NNode 5 [NEmpty])]), --    /|\  |
                  (NNode 6 [(NNode 7 [NEmpty])])]


size :: NTree a -> Int
size NEmpty = 0
size (NNode v ts) = 1 + sum (map size ts)