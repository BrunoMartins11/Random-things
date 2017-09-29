import Data.Char 

--  cicio 2 ficha2 de PF
--  ta em que os valores sao o drobro da lista de entrada
dobro :: [Float] -> [Float]
dobro (h:t) = h*2:dobro t

--  e vezes que ocorre um caracter numa string
numOcorre :: Char -> String -> Int
numOcorre _ [] = 0
numOcorre a (h:t) =	
	if a==h
    then 1+numOcorre a t 
    else numOcorre a t
--  lista so tem num positivos
positivos :: [Int] -> Bool
positivos [] = False
positivos (h:t) = if h<0 then False else positivos t
--  a lista so com positivos
soPos :: [Int] -> [Int]
soPos [a] = if a<=0 then [] else [a]
soPos (h:t) = if h<=0 then soPos t else h: soPos t
-- todos os num negativos da lista
somaNeg :: [Int] -> Int
somaNeg [a] = if a>=0 then 0 else a
somaNeg (h:t) = if h>=0 then somaNeg t else 1+somaNeg t
-- tres ultimos de uma lista
tresUlt :: [a] -> [a]
tresUlt (x:xs) = if (length (x:xs))<=3 then (x:xs) else tresUlt xs
-- todos os primeiros elementos de uma lista pares
primeiros :: [(a,b)] -> [a]
primeiros [] = []
primeiros ((x,y):t) = x:(primeiros t) 
--  exercico 4 ficha 2 PF 
-- a
primMai:: [Char] -> Bool
primMai (h:t) = isUpper h
-- b
segMin :: String -> Bool
segMin [] = True
segMin (x:xs) = if (isLower (head xs)) then True else False 
-- exercicio 5 ficha PF
--seleciona os algarismos de uma lista de char
soDigitos :: [Char] -> [Char]
soDigitos [] = []
soDigitos (h:t) = if isDigit h then (h : soDigitos t) else soDigitos t
-- conta quantas letras minusculas tem
minusculas :: [Char] -> Int
minusculas [] = 0
minusculas (x:xs) = if isLower x then 1+minusculas xs else minusculas xs
