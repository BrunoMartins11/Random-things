import System.Random
import Data.List
import Data.Char

bingo :: IO ()
bingo = do 
    geraNumeros [1..90]

geraNumeros :: [Int] -> IO () 
geraNumeros [] = putStrLn "acabou"
geraNumeros ns = do
    x <- randomRIO (0,90) :: IO Int
    if elem x ns 
    then do getChar
            putStrLn (show x)
            let newns = delete x ns
            geraNumeros newns
    else geraNumeros ns   


mastermind :: IO ()
mastermind = do 
    ns <- geraSequencia
    testaSeq  
    
  
geraSequencia ::  IO [Int]
geraSequencia = do 
         n1 <- randomRIO (0,9)
         n2 <- randomRIO (0,9)
         n3 <- randomRIO (0,9)
         n4 <- randomRIO (0,9)
         putStrLn  $ show (n1,n2,n3,n4)
         return [n1,n2,n3,n4]


testaSeq :: [Int] -> IO ()
testaSeq ns =  do 
    line <- getLine
    let (ok, quaseOk) = verifica line ns
    if (ok==4) then putStrLn "conseguiste"
               else do putStrLn ((show ok) ++ "\n" ++ show quase ok)
                       testaSeq ns

verifica :: [Char] -> [Int] -> Int -> (Int.Int)
verifica [] _ _ = (0,0)
verifica (h:t) ns pos
     | elem (digtitToInt h) ns  && ns!!pos == (digtitToInt h) = (ok +1 , quasOk)  
     | elem (digtitToInt h) ns                                = (ok,quasOk + 1)
     | otherwise                                              = (ok,quasOk)
                  where (ok,quasOk) = verifica t ns (pos+1)



