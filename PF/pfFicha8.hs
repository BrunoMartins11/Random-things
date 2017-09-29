data BTree a = Empty
             | Node a (BTree a) (BTree a)
       deriving Show
type Aluno = (Numero,Nome,Regime,Classificacao)
type Numero = Int
type Nome = String
data Regime = ORD | TE | MEL  deriving Show
data Classificacao = Aprov Int
                   | Rep
                   | Faltou
           deriving Show
type Turma = BTree Aluno  


--3a
inscNum :: Numero -> Turma -> Bool
inscNum n Empty = False
inscNum n (Node (x,y,r,c) e d) | n==x = True
                               | n<x  = inscNum n e
                               | otherwise = inscNum n d
--b
inscNome :: Nome -> Turma -> Bool
inscNome n Empty = False
inscNome (hs:ts) (Node (x,(h:t),r,c) e d) | (hs:ts)==(h:t) = True
                                          | hs < h = inscNome (hs:ts) e
                                          | otherwise = inscNome (hs:ts) d


--d
nota :: Numero -> Turma -> Maybe Classificacao
nota n Empty = Nothing
nota n (Node (x,y,r,c) e d) | n == x = Just c
                            | n < x  = nota n e 
                            | otherwise = nota n d 

{--e errada
percFaltas :: Turma -> Float
percFaltas Empty = 0
percFaltas Node (x,y,r,c) e d | c == Faltou = (1 + (percFaltas e) + percFaltas d)*100 /(contaNodos  Node (x,y,r,c) e d)
                              | otherwise = (((percFaltas e) + percFaltas d) * 100)/(contaNodos  Node (x,y,r,c) e d)
                  where contaNodos :: BTree a -> Int
                        contaNodos Empty = 0
                        contaNodos Node x e d = 1 + (contaNodos e ) + contaNodos d

--c
trabEst :: Turma -> [(Numero,Nome)]
trabEst Empty = []
trabEst (Node (x,y,r,c) e d) | r==TE  = (trabEst e) ++ [(x,y)] ++ trabEst d
                             | otherwise = (trabEst e) ++ trabEst d

--f 
mediaAprov :: Turma -> Float
mediaAprov Empty = 0
mediaAprov Node (x,y,r,Aprov w ) e d = (w + (mediaAprov e) + mediaAprov d)*100/(contaNodos  Node (x,y,r,p) e d)
                                       
                           where contaNodos :: BTree a -> Int
                                 contaNodos Empty = 0
                                 contaNodos Node x e d = 1 + (contaNodos e ) + contaNodos d
-}