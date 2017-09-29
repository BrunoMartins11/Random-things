type Hora = (Int,Int)
hora :: Hora -> Hora -> Hora
hora (a,b) (x,y) | a>x = (a,b)
                 | x>a = (x,y)
                 | x == a && b>y = (a,b)
                 | x == a && y>b = (x,y)