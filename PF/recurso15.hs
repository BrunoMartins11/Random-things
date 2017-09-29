type TurmaL = [(Numero,Aluno)]
type Aluno = (Nome,Nota)
type Numero = Int
type Nome = String
type Nota = Float

--1a
taxaAp :: TurmaL -> Float
taxaAp l = fromIntegral (aprov l) / fromIntegral (length l)
            where aprov :: TurmaL -> Int
                  aprov [] = 0
                  aprov ((n,(no,nota)):t) = if (nota) >= 9.5 then 1 + aprov t else aprov t  

--b
top :: Int -> TurmaL -> [String]
top n (h:t) = drop ((length (h:t))-n) (ordena (h:t) )
           where ordena :: TurmaL -> TurmaL
                 ordena [x] = [x] 
                 ordena ((n,(no,nota)):(n1,(no1,nota1)):t) = if nota >= nota1 then ordena ((n,(no,nota)):t) else ordena ((n1,(no1,nota1)):t)


--2a
data TurmaA = Al (Numero,Aluno)
            | Fork (Numero,Numero) TurmaA TurmaA

toList :: TurmaA -> TurmaL
toList             