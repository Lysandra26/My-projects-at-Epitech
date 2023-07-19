{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-MPL-4-1-compressor-nicolas.lefevre
-- File description:
-- Main
-}

module Main (main) where

import Imports
import Algo
import ErrorHandling
import Print

main :: IO ()
main = do
    args <- getArgs
    let status = parseOrUsage args
    case status of
        0 -> initAlgo args
        (-1) -> printUsage
        _ -> putStrLn "Error: invalid arguments" >> exitWith (ExitFailure 84)
