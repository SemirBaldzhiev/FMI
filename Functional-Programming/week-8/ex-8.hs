import Data.Char
import Data.List

main::IO()
main = do
    print (normalize "Attack London tomorrow at ten a.m.")
    print (encode ['A'..'Z'] 'A' 1) -- B
    print (encode ['A'..'Z'] 'C' 2 ) -- = 'E' [A,B,C,D,E,F,G]
    --print (encode ['A'..'Z'] 'Z' 3) --  = 'C'
    print (encode ['A'..'Z'] 'A' (-1)) --  = 'Z'
    print (encode ['A'..'Z'] 'C' (-2)) --  = 'A'
    print (encode ['A'..'Z'] 'Z' (-3)) --  = 'W'
    print (encode ['A'..'Z'] '@' 1) -- = error "unsupported symbol: @")

-- task-1    
normalize :: [Char] -> [Char]
normalize xs = helper xs []
    where
        helper [] res = res
        helper msg res
            |head msg >= '0' && head msg <= '9' = error "Cannot contains digits"
            |head msg >= 'a' && head msg <= 'z' = helper (tail msg) (res++[(toUpper (head msg))])
            |head msg >= 'A' && head msg <= 'Z'= helper (tail msg) (res++[(head msg)]) 
            |otherwise = helper (tail msg) res


contains :: [Char] -> Char -> Bool 
contains (a:as) ch = a == ch || contains as ch

-- task-2
--[A,C,D,F] D 1 -> F
getCharAt :: [Char] -> Char -> Int -> Char
getCharAt (a:as) ch ofs  = if ch == a then as!!(ofs-1) else getCharAt as ch ofs
encode :: [Char] -> Char -> Int -> Char 
encode alph ch offset = helper alph ch offset
    where
        helper alpha symbol off
            | not (contains alpha ch) = error "Unsupported symbol"
            | offset < 0 = encode (reverse alph) ch (-offset)
            | otherwise = getCharAt alph ch offset
            
               