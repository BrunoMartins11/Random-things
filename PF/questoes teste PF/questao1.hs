funA :: [Float] -> Float
funA [] = 0
funA (y:ys) = y^2 + (funA ys)