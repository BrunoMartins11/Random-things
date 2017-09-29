data Heap a = Vazia
            | Nodo a (Heap a) (Heap a)



existe :: Ord a => a -> Heap a -> Bool
existe x Vazia = False
existe x (Nodo a e d) | x < a  = False
                      | x == a = True
                      | otherwise = (existe x e) || (existe x d)


instance Eq Heap a where
(Nodo a Vazia Vazia) (Nodo a Vazia Vazia)
(Nodo a e d) == (Nodo b e1 d1) = (b==a) && (e==e1) && (d1==d)  
 