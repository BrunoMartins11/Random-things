--1
enumFromTo' :: Int -> Int -> [Int]
enumFromTo' x y = if (x<=y) then (x : (enumFromTo' (x+1) y)) else []
--2 
enumFromThenTo ::  Int -> Int -> Int -> [Int]
enumFromThenTo x y z = if x<=z then x : enumFromThenTo y (y-x) z else [] 
 --3
(++) :: [a] -> [a] -> [a]
(++) [] l = l
(++) (h:ts) list2 = h : ((++) ts list2)
-- 4 
last :: [a] -> a
last [x] = x
last (y:ys) = last ys
--5
init :: [a] -> [a]
init [x] = []
init (h:t) = h : (init t)
--6
(!!) :: [a] -> Int -> a
(!!) (x:xs) 0 = x
(!!) (y:ys) z = (!!) ys (z-1)
--7 (	errada)
reversw :: [a] -> [a]
reversw [x] = [x]
reversw [] = []
reversw (y:ys) = (reversw ys) : y  

--8
take :: Int -> [a] -> [a]
take 0 l = l
take n [] = []
take n (x:xs) = take (n-1) xs
--9
drop :: Int -> [a] -> [a]
drop 0 l = l
drop n [] = []
drop n (x:xs) = drop (n-1) xs
--10
zip :: [a] -> [b] -> (a,b)
zip [] l = []
zip l [] = []
zip  (x:xs) (y:ys) = (x:y) : (zip (xs) (ys))

--11
elem :: Eq a => a -> [a] -> Bool
elem x [] = False
elem x (y:ys) = if x=y then True else element x ys
--12
replicate :: Int -> a -> [a]
replicate 0 _ = []
replicate n x = x : (replicate (n-1) x)
--13
intersperse :: a -> [a] -> [a]
intersperse _ [] = []
intersperse _ [a] = [a]
intersperse x (y:ys) = y : x : intersperse x ys
--15
concat :: [[a]] -> [a]
concat [] = []
concat [[x]] [x]
concat ((x:xs):ys) =x:xs:(concat ys)
--17
tails :: [a] -> [[a]]
tails [] = [[]]
tails (x:xs) = (x:xs) : tails xs
--18
isPrefixOf' :: Eq a => [a] -> [a] -> Bool
isPrefixOf' [] l = True
isPrefixOf' l [] = False
isPrefixOf' (x:xs) (y:ys) = if (x == y) then isPrefixOf' xs ys else False
--19
isSuffixOf' :: Eq a => [a] -> [a] -> Bool
isSuffixOf' list1 list2 = isPrefixOf (reverse list1) (reverse list2)
--20
isSubsequenceOf ::  Eq a => [a] -> [a] -> Bool
isSubsequenceOf [] l = True
isSubsequenceOf l [] = False
isSubsequenceOf (x:xs) (y:ys) = if x == y then isSubsequenceOf xs ys else isSubsequenceOf (x:xs) y
--23
delete ::  Eq a => a -> [a] -> [a]
delete g [] = []
delete y (x:xs) = if x==y then xs else x : delete y xs 
--24
(\\) :: Eq a => [a] -> [a] -> [a]
(\\) [] _ = []
(\\) list [] = list
(\\) list (x:xs) = (\\) (delete x list) xs

-- 25)
union :: Eq a => [a] -> [a] -> [a]
union l1 l2 = l1 ++ (l2 \\ l1)
--26(errada)
intersect  ::  Eq a => [a] -> [a] -> [a]
intersect _ [] = []
intersect (x:xs) (y:ys) = if x==y then (if (head xs) == y then x : (head xs) : (intersect (tail xs) (y:ys)) else x : (intersect xs (y:ys)))
                                                          else intersect xs (y:ys)    
--27
insert ::  Ord a => a -> [a] -> [a]
insert z [] = [z]
insert x (y:ys) = if x>y then y : (insert x ys) else x:(y:ys)
--28
maximum ::  Ord a => [a] -> a
maximum [] = 0 -- no caso de pargem como nao esta definido retorna 0
maximum [x] = x  
maximum (x:xs) = aux x xs 
               where aux x [] = x 
               	aux x xs = if x<(head xs) then aux (head xs) (tail xs) 
               	                               else aux x (tail xs) 
--29
minimum :: Ord a => [a] -> a 
minimum [x] = x 
minimum (x:xs) = aux x xs
               where aux x [] = x 
               	     aux x xs = if x<(head xs) then aux x (tail xs)
               	                               else aux (head xs) (tail xs)

--30
sum :: Num a => [a] -> a
sum [] = []
sum (x:xs) = x + (sum xs)
--31
product :: Num a => [a] -> a 
product [] = 1
product (x:xs) = x * (product xs)
--32
and :: [Bool] -> Bool
and [] = True
and (x:xs) = if x == True then and xs else False
--33
or :: [Bool] -> Bool
or [] = False
or (x:xs) = if x==False then or xs else True
--34
unwords :: [String] -> String
unwords [] = ""
unwords [x] = x
unwords (x:xs) = x ++ (" ") ++ unwords xs
--35
unlines :: [String] -> String
unlines [] = ""
unlines [x] = x ++ ("\n")
unlines (x:xs) = x ++ ("\n") ++ unlines xs 
--36
pMaior :: Ord a => [a] -> Int
pMaior (x:xs) = aux2 (aux1 x xs) (x:xs)
              where aux1 x [] =  x
              	    aux1 x xs = if x > (head xs) then aux1 x (tail xs)
                                                 else aux1 (head xs) (tail xs)	
                    aux2 n (x:xs) = if n==x then 0 else 1 + (aux2 n xs)          
--37
temRepetidos :: Eq a => [a] -> Bool
temRepetidos [] = False
temRepetidos (x:xs) = if (elem x xs) then True else temRepetidos xs
--38
algarismos :: [Char] -> [Char]
algarismos "" = ""
algarismos (x:xs) = if x>='0' && x<='9' then x : algarismos xs else algarismos xs
--39
posImpares :: [a] -> [a]
posImpares [] = []
posImpares [x] = []
posImpares (x:xs) = (head xs) : posImpares (tail xs)
--40																												
posPares :: [a] -> [a]
posPares [] = []
posPares [x] = [x]
posPares (x:z:xs) = x : posPares xs
--41
isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted [y] = True
isSorted (x:xs) = if x > (head xs) then False else isSorted xs 
--42
iSort :: Ord a => [a] -> [a]
iSort [] = []
iSort [x] = [x]
iSort (x:xs) =aux (x:xs) []
where aux [] l = l
	  aux (x:xs) y = aux xs (insert x y) 
--43 errada
menor :: String -> String -> Bool
menor _ [] = False
menor (x:xs) (y:ys) = if (length x) < (length y) then True  else menor xs ys 



--44
elemMSet :: Eq a => a -> [(a,Int)] -> Bool
elemMSet x [] = False
elemMSet y ((h,z):ts) = if y == h then True else elemMSet y ts 
--45
lengthMSet :: [(a,Int)] -> Int
lengthMSet [] = 0
lengthMSet ((x,y):ts) = y + (lengthMSet ts)
--46
converteMSet :: [(a,Int)] -> [a]
converteMSet [] = []
converteMSet ((x,y):ts) = if y>0 then x : converteMSet ((x,y-1):ts) else converteMSet ts
--47
insereMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
insereMSet x [] = [(x,1)]
insereMSet x ((y,z):ys) = if x==y then ((y,z+1):ys) else (y,z) : insereMSet x ys
--48
removeMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
removeMSet x [] = []
removeMSet x ((y,z):ys) = if x == y then (if z-1==0 then ys else ((y,z-1):ys)) 
	                                else (y,z) : removeMSet x ys













--50
somaPares :: [Int] -> Int
somaPares [] = 0
somaPares (x:xs) = if (mod x 2) == 0 then x + somaPares xs else somaPares xs





















































































































