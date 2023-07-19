{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-MPL-4-1-compressor-nicolas.lefevre
-- File description:
-- ErrorHandling
-}

module ErrorHandling (parseArgs, parseOrUsage, isUsage) where

import Imports
import Tools

parseOrUsage :: [String] -> Int
parseOrUsage args =
  if isUsage args == (-1) then
    (-1)
  else
    parseArgs args

parseArgs :: [String] -> Int
parseArgs ["-n", nStr, "-l", lStr, "-f", _] =
  case (readMaybe nStr :: Maybe Integer, readMaybe lStr :: Maybe Double) of
    (Just n, Just l) | n `elem` [2..8] && l >= 0 && l <= 1 -> 0
    _ -> 1
parseArgs _ = 1

