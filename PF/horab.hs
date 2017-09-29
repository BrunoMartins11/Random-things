type Hora = (Int,Int)
hora :: Hora -> Int -> Hora
hora (x,y) m | y+m>59 && m>60 = (x+(div m 60) , y+(mod m 60))
             | y+m<60 = (x,y+m) 
             | y+m>59 && m<60 = (x+(div (m+y) 60) , y+(mod (m+y) 60))
