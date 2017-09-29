-- ficha 3 Pf
--2a
segundos :: [(a,b)] -> [b]
segundos [] = []
segundos ((x,y):t) = y : segundos t
--b
