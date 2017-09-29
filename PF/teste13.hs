module Main where


type Album = (Titulo,Artista,Ano,[Musica])
type Musica = (Nome,Int)        
type Titulo = String
type Nome = String
type Artista = String
type Ano = Int

--1
doArtista :: [Album] -> Artista -> [(Titulo,Ano)]
doArtista [] _ = []
doArtista ((t,a,an,m):ts) art = if art==a then (t,an):(doArtista ts art) else doArtista ts art

{-
conta :: [Artista] -> [Album] -> [(Artista,Int)]
conta (h:t) ((ti,art,ano,m):ts) = (contaAux h ((ti,art,ano,m):ts) ) ++ conta t ((ti,art,ano,m):ts)
                             where contaAux :: Artista -> [Album] -> [(Artista,Int)]
                                   contaAux x [] = []
                                   contaAux x ((ti,art,ano,m):ts) = if x==art then [soma ((x,1):(contaAux x ts))] else [contaAux x t]

soma :: [(Artista,Int)] -> (Artista,Int) 
soma ((x,y):t) = (x,length((x,y):t))
-}
--3
maisAntigos :: [Album] -> [Album]
maisAntigos [] = []
maisAntigos ((ti,art,ano,m):ts) = (compara (ti,art,ano,m) ts): maisAntigos (apaga1 (compara (ti,art,ano,m) ts) ((ti,art,ano,m):ts)) 
                          where compara :: Album -> [Album] -> Album
                                compara x [] = x
                                compara (ti1,art1,x,m1) ((ti,art,ano,m):ts) = if x<ano then compara (ti1,art1,x,m1) ((ti,art,ano,m):ts) else compara (ti,art,ano,m) ts
apaga1 :: Album -> [Album] -> [Album]
apaga1 x (h:t) = if x==h then t else h:apaga1 x t

--2TESTE
data Tree a = Empty
            | Leaf a
            | Fork (Tree a) (Tree a)

{-instance Show a => Show Tree a where
show (Leaf a) = a
show (Fork a b) = "("++(show a)++ "<-*->"++(show b) ++")"
show (Empty)  = "<>" 
-}
--2
ultimo :: Tree a -> Maybe a
ultimo (Fork e d) = aux (ultimoAux (Fork e d))
            where ultimoAux :: Tree a -> [a]
                  ultimoAux (Leaf x) = [x]
                  ultimoAux Empty = []
                  ultimoAux (Fork e d) = (ultimoAux e) ++ (ultimoAux d)

aux :: [a] -> Maybe a
aux [] = Nothing
aux l = Just (last l)

--3
apaga :: Eq a => a -> Tree a -> Tree a
apaga x (Leaf y) = if x==y then Empty else (Leaf y)
apaga x Empty = Empty
apaga x (Fork e d) = Fork (apaga x e) (apaga x d)


--4
limpa :: Tree a -> Tree a
limpa Empty = Empty
limpa (Leaf x) = Leaf x
limpa (Fork e Empty) = limpa e
limpa (Fork Empty d) = limpa d 
limpa (Fork e d) = Fork (limpa e) (limpa d)

inits :: [a] -> [[a]]
inits [] =[[]]
inits l = inits (init l) ++ [l]


type Aluno = (Numero,Nom,Classificacao)
type Numero = Int
type Nom = String
data Classificacao = Aprov Int | Rep | Faltou
data Turma = Vazia | Nodo Aluno Turma Turma


aprovAv :: Turma -> Float
aprovAv Vazia = 0
aprovAv (Nodo (n,no,Aprov cl) e d) = (fromIntegral (1 + aprovAv e + aprovAv d)) / (fromIntegral (contaNodo (Nodo (n,no,Aprov cl) e d)))
aprovAv (Nodo (n,no,Rep) e d) = (fromIntegral (aprovAv e + aprovAv d)) / (fromIntegral (contaNodo (Nodo (n,no, Rep) e d)))
aprovAv (Nodo (n,no,Faltou) e d) = (fromIntegral (aprovAv e + aprovAv d)) / (fromIntegral (contaNodo (Nodo (n,no,Faltou) e d)))
                                    
contaNodo Vazia = 0
contaNodo (Nodo r e d) = 1 + contaNodo e + contaNodo d




melhorNota :: Turma -> Maybe Int
melhorNota Vazia = Nothing
melhorNota (Nodo (n,no,Rep) e d) = comp2 (melhorNota e)  (melhorNota d) 
melhorNota (Nodo (n,no,Faltou) e d) = comp2 (melhorNota e) (melhorNota d)
melhorNota (Nodo (n,no,Aprov cl) e d) = if (compara cl e) > (compara cl d) then Just (compara cl e) else Just (compara cl d) 

compara :: Int -> Turma -> Int
compara x Vazia = x
compara x (Nodo (n,no,Rep) e d)    = if (compara x e) > (compara x d) then  (compara x e) else (compara x d) 
compara x (Nodo (n,no,Faltou) e d) = comp (compara x e)  (compara x d)
compara x (Nodo (n,no,Aprov cl) e d) = if x>= cl then comp (compara x e) (compara x d) else comp (compara cl e) (compara cl d)

comp x y = if x> y then x else y

comp2 Nothing (Just x) = Just x
comp2 (Just x) Nothing = Just x
comp2 (Just x) (Just y) = if x> y then Just x else Just y