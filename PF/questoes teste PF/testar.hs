menor :: String -> String -> Bool
menor _ [] = False
menor (x:xs) (y:ys) = if (length x) < (length y) then True  else menor xs ys 