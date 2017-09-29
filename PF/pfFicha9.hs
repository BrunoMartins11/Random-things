data Frac = F Integer Integer
    

--1a
normaliza :: Frac -> Frac
normaliza (F x y) = (F ( x `div` (mdc x y)) ( y `div` (mdc x y)))

mdc :: Integer -> Integer -> Integer
mdc x y = mdc2 (abs x) (abs y) 

mdc2 :: Integer -> Integer -> Integer
mdc2 x y | x > y = mdc2 (x-y) y
         | x < y = mdc2 x (y-x)
         | otherwise = x

--b
instance Eq Frac where
    f1 == f2 = (normaliza f1) `igual1` (normaliza f2)

igual1 (F x1 y1) (F x2 y2 ) = x1==x2 && y1 == y2

--c 
instance Ord Frac where
    (<=) (F x1 y1) (F x2 y2) = ((fromInteger x1)/(fromInteger y1)) <= ((fromInteger x2)/(fromInteger y2))

--d 
instance Show Frac where
    show (F x1 y1) = (show x1) ++ "/" ++ show y1

--e 
instance Num Frac where
    (+) (F x1 y1) (F x2 y2) = normaliza (F ((x1*y2) + (x2*x1)) (y1*y2)) 
    (-) (F x1 y1) (F x2 y2) = normaliza (F ((x1*y2) - (x2*x1)) (y1*y2))
    (*) (F x1 y1) (F x2 y2) = normaliza (F (x1*x2) (y1*y2))
    
                             