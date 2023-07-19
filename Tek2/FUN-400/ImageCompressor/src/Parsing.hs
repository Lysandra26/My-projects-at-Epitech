{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-MPL-4-1-compressor-nicolas.lefevre
-- File description:
-- Parsing
-}

module Parsing (fileIsExists, parseFile, parseLine, parseCoords, parseColors) where

import Imports
import System.IO.Error (catchIOError, isDoesNotExistError)

fileIsExists :: String -> IO Int
fileIsExists path =
    catchIOError
        (withFile path ReadMode (\_ -> return 0))
        (\e -> if isDoesNotExistError e then return 1 else ioError e)


parseFile :: String -> IO [[Int]]
parseFile path = do
  contents <- readFile path
  let linesList = lines contents
  return $ map parseLine linesList

parseLine :: String -> [Int]
parseLine line = case words line of
    [coordsStr, colorsStr] -> let coords = parseCoords coordsStr
                                  colors = parseColors colorsStr
                              in coords ++ colors
    _                      -> [(-1), (-1), (-1), (-1), (-1)]

parseCoords :: String -> [Int]
parseCoords str = case readMaybe str of
    Just (x,y) -> [x,y]
    Nothing    -> [(-1), (-1), (-1), (-1), (-1)]

parseColors :: String -> [Int]
parseColors str = case readMaybe str of
    Just (r,g,b) -> [r,g,b]
    Nothing      -> [(-1), (-1), (-1), (-1), (-1)]