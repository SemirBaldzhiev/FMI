main :: IO()
main = do
    --print (perimeter (Circle 2))
    --print (biggestArea [shape1,shape2, shape3])
    --print (distance p1 p2)
    --print (getClosestPoint [p2, p3, p4] p1)
    print (getClosestDistance [p1, p2, p3, p4])

shape1 :: Shape
shape1 = Circle 2
shape2 :: Shape
shape2 = Rectangle 3 4
shape3 :: Shape
shape3 = Triangle 6 7 9

p1 :: Point
p1 = PlnePoint 1 2

p2 :: Point
p2 = PlnePoint 3 4
p3 :: Point
p3 = PlnePoint 5 6
p4 :: Point
p4 = PlnePoint 7 8


data Shape = Circle Double | Rectangle Double Double | Triangle Double Double Double 
    deriving Show

data Point = PlnePoint Double Double | SpacePoint Double Double Double
    deriving (Show, Ord)

instance Eq Point where
    (==) (PlnePoint x1 y1) (PlnePoint x2 y2) = x1 == x2 && y1 == y2
    (==) (SpacePoint x1 y1 z1) (SpacePoint x2 y2 z2) = x1 == x2 && y1 == y2 && z1 == z2

perimeter :: Shape -> Double
perimeter (Circle r) = 2 * 3.14 * r
perimeter (Rectangle a b) = 2 * a + 2 * b; 
perimeter (Triangle a b c) = a + b + c

semiPerimeter :: Shape -> Double
semiPerimeter sh@(Triangle a b c) = perimeter sh / 2

area :: Shape -> Double
area (Circle r) = 3.14 * r * r
area (Rectangle a b) = a * b
area t@(Triangle a b c) = sqrt(semiPerimeter t *(semiPerimeter t - a) * (semiPerimeter t - b) * (semiPerimeter t))

isRound :: Shape -> Bool
isRound (Circle _) = True
isRound (Rectangle _ _) = False
isRound (Triangle _ _ _) = False

is2D :: Shape -> Bool
is2D _ = True

sumArea :: [Shape] -> Double
sumArea [] = 0
sumArea (x:xs) = area x + sumArea xs

biggestArea :: [Shape] -> Shape
biggestArea [x] = x
biggestArea [x,y] = if area x > area y then x else y
biggestArea (x:y:xs)
    | area x > area y = biggestArea (x:xs)
    | otherwise = biggestArea (y:xs) 


distance :: Point -> Point -> Double
distance (PlnePoint x1 y1) (SpacePoint x2 y2 z2) = error "Different points"
distance (PlnePoint x1 y1) (PlnePoint x2 y2) = sqrt((x2 - x1)^2 + (y2 - y1)^2)
distance (SpacePoint x1 y1 z1) (SpacePoint x2 y2 z2) = sqrt((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)

getClosestPoint :: [Point] -> Point -> Point
getClosestPoint points p1 = (fst . minimum) [(p, distance p p1) | p <- points]

getClosestDistance :: [Point] -> (Double, Point, Point)
getClosestDistance ps = minimum [((distance p1 p2), p1 , p2) | p1 <- ps, p2 <- ps, p1 /= p2]



