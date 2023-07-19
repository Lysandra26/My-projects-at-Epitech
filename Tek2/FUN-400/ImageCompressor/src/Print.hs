{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-MPL-4-1-compressor-nicolas.lefevre
-- File description:
-- Print
-}

module Print (printUsage) where

printUsage :: IO ()
printUsage =
    putStrLn "USAGE: ./imageCompressor -n N -l L -f F" >>
    putStrLn "" >>
    putStrLn "      N       number of colors in the final image" >>
    putStrLn "      L       convergence limit" >>
    putStr "      F       path to the file containing" >>
    putStrLn " the colors of the pixels"
