import Data.List

nub' :: Eq a => [a] -> [a]
nub' [] = []
nub' (h:t) =if elem h t then nub' t else h : nub' t

--b
zipWith' :: (a->b->c) -> [a] -> [b] -> [c]
zipWith' _ [] []  = []
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (h:t) (x:xs) = (f h x) : zipWith' f t xs

--2
--a
type MSet a = [(a,Int)]

converte :: Eq a => [a] -> MSet a
converte [] = []
converte (h:t) = conta 1 h t : converte (apaga h t)
            where conta :: Eq a => Int -> a -> [a] -> (a,Int)
                  conta n x [] = (x,n)
                  conta n x (h:t) = if x == h then conta (n+1) x t else conta n x t

                  apaga :: Eq a => a -> [a] -> [a]
                  apaga x [] = []
                  apaga x (h:t) = if x == h then apaga x t else h : apaga x t

--b
intersect :: Eq a => MSet a -> MSet a ->MSet a
intersect [] _ = []
intersect _ [] = []
intersect ((x,c):xs) ((y,t):ys) = menor (match (igual ((x,c):xs) ((y,t):ys)) ((x,c):xs) ((y,t):ys))
                                 where igual :: Eq a => MSet a -> MSet a -> [a]
                                       igual _ [] = []
                                       igual [] _ = []
                                       igual ((x,c):xs) ((y,t):ys) = if x == y then x:

--3
data Prop = Var String | Not Prop | And Prop Prop | Or Prop Prop
--a
p1 :: Prop
show (Var a) = a
show (Not prop) ="-" ++ show prop
show (Or prop1 prop2) = show prop1 ++ "\/" ++ show prop2
show (And prop1 prop2) = show prop1 ++ "/\"" ++ show prop2