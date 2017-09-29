type TabClass = [(Piloto,Equipa,Pontos)]
type Piloto = String
type Pontos = Int
type Equipa = String
--1a
pontosEquipa :: Equipa -> TabClass -> Pontos
pontosEquipa _ [] = 0
pontosEquipa x ((p,e,po):t) = if x == p then po + pontosEquipa x t else pontosEquipa x t

--b
junta :: [Piloto] -> TabClass -> TabClass
junta [] _ = []
junta (h:t) ((p,e,po):ts) = if h == p then (p,e,po+(calculaPonto (h:t))): junta t ts else junta (h:t) ts
                                       where calculaPonto :: [Piloto] -> Int
                                             calculaPonto l | (length l) == 1 = 1
                                                            | (length l) == 2 = 2
                                                            | (length l) == 3 = 4
                                                            | (length l) == 4 = 6
                                                            | (length l) == 5 = 8
                                                            | (length l) == 6 = 10
                                                            | (length l) == 7 = 12
                                                            | (length l) == 8 = 15
                                                            | (length l) == 9 = 18
                                                            | (length l) == 10 = 25


ordena :: TabClass -> TabClass
ordena []  = []
ordena [x] = [x]
ordena (h:t) = (ordenaAux [h] t) ++ ordena (apaga (h:t))  
            where ordenaAux :: TabClass -> TabClass -> TabClass
                  ordenaAux [x] [] = [x]
                  ordenaAux [(p,e,po)] ((p1,e1,po1):t) = if po >= po1 then ordenaAux [(p,e,po)] t else ordenaAux [(p1,e1,po1)] t
apaga :: TabClass -> TabClass
apaga [x] = []
apaga ((p,e,po):(p1,e1,po1):t) = if po >= po1 then apaga ((p,e,po):t) else apaga ((p1,e1,po1):t)
--2a
type Mat a = [[a]]

{- zipWMat :: (a -> b -> c) -> Mat a -> Mat b -> Mat c
zipWMat f [] _ = []
zipWMat f _ [] = []
zipWMat f (x:xs) (y:ys) = (somar x y) : zipWMat f xs ys 
                   where somar :: Eq a => [a] -> [a] -> [a]
                         somar (h:ts) (hs:t) = (h+hs) : somar ts t
-}
--b
{-triSup :: Eq a => Mat a -> Bool
triSup ((h:t):ts) = if h /= 0 then triSupAux ts 0 else False
                          where triSupAux :: Eq a => Mat a -> Int -> Bool
                                triSupAux [[x]] c = True
                                triSupAux ((h:t):ts) c = if ((h !! c) == 0) then (triSupAux ts c) && (triSupAux ts (c+1)) else False
                                -}
--c 
rotateLeft :: Mat a -> Mat a
rotateLeft [] = []
rotateLeft (h:t) = rotate (h:t) ((length h)-1)
                 where rotate :: Mat a -> Int -> Mat a
                       rotate [] _ = []
                       rotate (h:t) c = (rotateAux (h:t) c) : rotate (h:t) (c-1)
rotateAux :: Mat a -> Int -> [a]
rotateAux l 0    = []
rotateAux (h:t) c = h!!c : rotateAux t c

--3 a
data Questionario = Solucao String
                  | Questao String Questionario Questionario

respostas :: Questionario -> [String]
respostas (Solucao x) = [x]
respostas (Questao a e d) = (respostas e) ++ (respostas d )
--b
 