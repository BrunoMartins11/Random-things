--1a

posNeg :: [Int] -> (Int,Int)
posNeg [] = (0,0)
posNeg (h:t) = if h >= 0 then soma (1,0) (posNeg t) else soma (0,1) (posNeg t)
                             where soma :: (Int,Int) -> (Int,Int) -> (Int,Int)
                                   soma (x,y) (w,z) = (x+w,z+y) 
--b
tiraPrefixo :: String -> String -> Maybe String
tiraPrefixo "" s = Just s
tiraPrefixo (h:t) (hs:ts) = if h==hs then tiraPrefixo t ts else Nothing 

--c
fun :: [Int] -> Int
fun l = product l

fun1 :: [Int] -> [Int]
fun1 (h:t) = if h > 0 then (fun2 h):fun1(t) else fun1 t 

fun2 :: Int -> Int
fun2 x = undefined

--d 
data ArvBin a = Vazia | Nodo a (ArvBin a) (ArvBin a)

insere ::  Ord a => a -> ArvBin a -> ArvBin a
insere x Vazia = Nodo x Vazia Vazia
insere x (Nodo r e d) = if x < r then Nodo r (insere x e) d else Nodo r e (insere x d)

--e
type Concorrentes = [(Numero, String)]    
type Numero = Int
type Prova = [(Numero, Float)]              

nomes :: Prova -> Concorrentes -> [(String,Float)]
nomes _ [] =[]
nomes ((num,temp):t) ((num1,no):ts) = if num==num1 then (no,temp):(nomes t ts) else (nomesAux (num,temp) ts):(nomes t ((num1,no):ts))
                                        where nomesAux :: (Int,Float) -> Concorrentes -> (String,Float)
                              
                                              nomesAux (num2,temp2) ((num1,no):ts) =  if num2 == num1 then (no,temp) else nomesAux (num2,temp2) ts
ordena :: Prova -> Prova
ordena [] = []
ordena ((num,temp):t) = if maior temp t then (num,temp) : ordena t else ordena (t++[(num,temp)])
                         where maior :: Float -> Prova -> Bool
                               maior x [] = True
                               maior x ((num,temp):t) = if x >= temp then maior x t else False

--II
--1a


camValido :: ArvBin a -> [Bool] -> Bool
camValido (Nodo r Vazia Vazia) [] = True
camValido (Nodo r Vazia Vazia) _  = False
camValido (Nodo r e d) (h:t) = if h==True then camValido d t else camValido e t
	
--b
caminho :: (Eq a) => ArvBin a -> a -> Maybe [Bool]
caminho (Nodo r e d) x = if petence x (Nodo r e d) then Just (caminhoAux (Nodo r e d) x)

fazParte :: (Eq a) => ArvBin a -> a -> Bool
fazParte Vazia x = False
fazParte (Nodo r e d) x = if x==r then True else fazParte e x || fazParte d x 

caminhoAux :: (Eq a) => ArvBin a -> a -> [Bool]
caminhoAux (Nodo r e d) x = if x==r then [] else if fazParte e x then False : caminhoAux e r else True :caminhoAux d r 
