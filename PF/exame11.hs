type MSet a = [(a,Int)]

--1a
add :: (Ord a) => [a] -> MSet a
add (h:t) = (h,addAux h t): add (apaga h t)

   where addAux :: (Ord a) => a -> [a] -> Int
         addAux _ [] = 0 
         addAux h (x:xs) = if h==x then 1 + addAux h xs else addAux h xs

apaga :: (Ord a) => a -> [a] -> [a]
apaga _ []    = []
apaga x (h:t) = if x == h then apaga x t else h:apaga x t 

--b
moda :: MSet a -> a
moda ((x,y):t) = modaAux (x,y) t
                where modaAux :: (a,Int) -> MSet a -> a
                      modaAux (x,y) [] = x
                      modaAux (x,y) ((x1,y1):t) = if y>=y1 then modaAux (x,y) t else modaAux (x1,y1) t


--c
mIntersect :: (Ord a) => MSet a -> MSet a -> MSet a
mIntersect _ [] = []
mIntersect [] _ = []
mIntersect ((w,z):t) ((x,y):xs) | w == x = (menor (w,z) (x,y)): mIntersect t xs
                                | otherwise = mIntersect ((w,z):t) xs 
                                    where menor :: (a,Int) -> (a,Int) -> (a,Int)
                                          menor (x,y) (w,z) = if y>=z then (x,y) else (x,z)

--2a
data BTree a = Vazia | Nodo a (BTree a) (BTree a)


limites :: BTree a -> (a,a)
limites (Nodo r Vazia Vazia) = (r,r)
limites (Nodo a e d) = (menor e ,maior d)
                 where menor :: BTree a -> a
                       menor (Nodo r Vazia Vazia) = r
                       menor (Nodo r e d) = menor e
maior:: BTree a -> a
maior (Nodo r Vazia Vazia) = r
maior (Nodo r e d) = maior d

--b
media :: BTree Float -> Float
media (Nodo r e d) = fromRational (fromIntegral (soma (Nodo r e d )) / fromIntegral (contaNodos Nodo r e d))

soma :: BTree Float -> Float
soma (Nodo r Vazia Vazia) = r
soma (Nodo r e d) = r + (soma e) + soma d

contaNodos :: BTree Float -> Int
contaNodos Vazia = 0
contaNodos (Nodo r e d) = 1 + (contaNodos e) + contaNodos d



























