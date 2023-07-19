{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-MPL-4-1-compressor-nicolas.lefevre
-- File description:
-- Tools
-}

module Tools (getLastListElement, errorExit, isNeg, isGood, hasDuplicates, findK, isUsage) where

import Imports

getLastListElement :: [Int] -> Int -> Int
getLastListElement [y, x, _, _, _] n = if n == 0 then y else x
getLastListElement _ _ = 0


errorExit :: String -> IO ()
errorExit reason =
    putStrLn reason >> exitWith (ExitFailure 84)

isNeg :: [[Int]] -> Int
isNeg xss
  | any (== -1) (concat xss) = -1
  | otherwise = 0


isGood :: [[Int]] -> Int
isGood contents =
    let firstLine = if null contents
        then [(-1), (-1), (-1), (-1), (-1)] else head contents
    in if firstLine == [(-1), (-1), (-1), (-1), (-1)] || isNeg contents == (-1) then
        (-1)
    else
        0

hasDuplicates :: [[Int]] -> Int
hasDuplicates xs =
    if length xs == length (nub xs) then
        1
    else
        -1
findK :: [String] -> Int
findK ("-n" : nStr : _) = (read nStr)
findK _                = 0

isUsage :: [String] -> Int
isUsage args = if null args then (-1) else 1
