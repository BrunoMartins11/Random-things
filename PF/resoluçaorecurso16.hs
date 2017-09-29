import Data.List
import Data.Function

--1a
intersperse1 :: a -> [a] -> [a]
intersperse1 _ [y] = [y]
intersperse1 x (h:t) = h : x : intersperse1 x t

--b
--inits1 :: [a]->[[a]]
--inits1 [] = []
--inits1 (h:t) = (inits1 (take 1 (h:t)) ): (h:t)

--2

type Aluno = (Numero,Nome,Classificacao)
type Numero = Int
type Nome = String
data Classificacao = Aprov Int | Rep | Faltou
data Turma = Vazia | Nodo Aluno Turma Turma
            
--a
inscNum :: Numero -> Turma -> Bool
inscNum _ Vazia = False
inscNum n (Nodo (nu,no,cl) e d) = if n==nu then True else (inscNum n e) || (inscNum n d)  

{--b
aprovAv :: Turma -> Float
aprovAv Vazia = 0
aprovAv (Nodo (nu,no,Rep) e d)     =(fromIntegral ((aprovAv e) + (aprovAv d)))     / (fromIntegral(contaAlunos (Nodo (nu,no,Rep) e d))) 
aprovAv (Nodo (nu,no,Aprov w) e d) =(fromIntegral (1 + (aprovAv e) + (aprovAv d))) / (fromIntegral(contaAlunos (Nodo (nu,no,Aprov w) e d)))
aprovAv (Nodo (nu,no,Faltou) e d)  =(fromIntegral ((aprovAv e) + (aprovAv d)))     / (fromIntegral(contaAlunos (Nodo (nu,no,Faltou) e d)))
                                           
contaAlunos :: Turma -> Int 
contaAlunos Vazia = 0
contaAlunos (Nodo (nu,no,cl) e d) = 1 + (contaAlunos e) + contaAlunos d 
-}
--c
melhorNota :: Turma -> Maybe Int
melhorNota (Nodo (nu,no,cl) e d ) = notaAux 0 (Nodo (nu,no,cl) e d )
                                where notaAux :: Int -> Turma -> Maybe Int
                                      notaAux 0 Vazia = Nothing
                                      notaAux n Vazia = Just n
                                      notaAux n (Nodo (nu,no,Aprov w) e d ) = if n <= w then nota (notaAux w e)  (notaAux w d) else nota (notaAux n e) (notaAux n d)
                                      notaAux n (Nodo (nu,no,Rep) e d ) = nota (notaAux n e) (notaAux n d)
                                      notaAux n (Nodo (nu,no,Rep) e d ) = nota (notaAux n e) (notaAux n d)
nota :: Int -> Int -> Int
nota n1 n2 = if n1 > n2 then n1 else n2