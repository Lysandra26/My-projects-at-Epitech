{-
-- EPITECH PROJECT, 2023
-- bonus
-- File description:
-- bubble_sort
-}

import System.Environment

sortOnce :: Ord a => [a] -> [a]
sortOnce xs =
    let sorted = sortOnce xs
    in if xs == sorted
        then sorted
        else sortOnce sorted
    where
    sortOnce (x:y:xs)
        | x > y = y : sortOnce (x:xs)
        | otherwise = x : sortOnce (y:xs)
    sortOnce xs = xs

bubbleSort :: Ord a => [a] -> [a]
bubbleSort xs =
    let sorted = sortOnce xs
    in if xs == sorted
        then xs
        else bubbleSort sorted

main :: IO ()
main = do
    args <- getArgs
    let xs = map read args :: [Int]
        sorted = sortOnce xs
    putStrLn "The result is:"
    print sorted