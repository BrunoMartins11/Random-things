import System.Environment
import Text.Read
import Data.Maybe
import Data.List
import System.Random

posiçaoBomba :: [String] -> (Int,Int)
posiçaoBomba ((h:t):ts) = if (h == '*') && last (words (h:t)) == (show 0) then ((read(words (h:t))!!1),(read(words (h:t))!!2))  else posiçaoBomba ts