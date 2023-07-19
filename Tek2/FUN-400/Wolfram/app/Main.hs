{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-MPL-4-1-wolfram-lysandra.manuguerra
-- File description:
-- Main
-}

module Main where

-- import Wolfram

import System.Environment
import System.Exit

data Options = Options
    { rule :: Maybe Int
    , start :: Int
    , linesToDisplay :: Maybe Int
    , windowSize :: Int
    , windowMove :: Int
    }

defaultOptions :: Options
defaultOptions = Options
    { rule = Nothing
    , start = 0
    , linesToDisplay = Nothing
    , windowSize = 80
    , windowMove = 0
    }

parseArgs :: [String] -> Either String Options
parseArgs [] = Left "Missing rule option"
parseArgs ("--rule":r:xs) = case reads r of
    [(n,"")] -> Right $ defaultOptions { rule = Just n }
    _ -> Left "Invalid rule number"
parseArgs ("--start":s:xs) = case reads s of
    [(n,"")] -> case parseArgs xs of
        Left err -> Left err
        Right opts' -> Right $ opts' { start = n }
    _ -> Left "Invalid start number"
parseArgs ("--lines":l:xs) = case reads l of
    [(n,"")] -> case parseArgs xs of
        Left err -> Left err
        Right opts' -> Right $ opts' { linesToDisplay = Just n }
    _ -> Left "Invalid number of lines"
parseArgs ("--window":w:xs) = case reads w of
    [(n,"")] -> case parseArgs xs of
        Left err -> Left err
        Right opts' -> Right $ opts' { windowSize = n }
    _ -> Left "Invalid window size"
parseArgs ("--move":m:xs) = case reads m of
    [(n,"")] -> case parseArgs xs of
        Left err -> Left err
        Right opts' -> Right $ opts' { windowMove = n }
    _ -> Left "Invalid window move"
parseArgs _ = Left "Invalid options"

usage :: String -> IO a
usage err = do
    putStrLn $ "Error: " ++ err
    putStrLn "Usage: ./program --rule <RULE> [--start <START>] [--lines <LINES>] [--window <WINDOW>] [--move <MOVE>]"
    exitWith $ ExitFailure 84

main :: IO ()
main = do
    args <- getArgs
    case parseArgs args of
        Left err -> usage err
        Right opts -> do
            case rule opts of
                Nothing -> usage "Missing rule option"
                Just _ -> return ()
            putStrLn $ "Rule: " ++ show (rule opts)
            -- putStrLn $ "Start: " ++ show (start opts)
            -- putStrLn $ "Lines: " ++ show (linesToDisplay opts)
            -- putStrLn $ "Window size: " ++ show (windowSize opts)
            -- putStrLn $ "Window move: " ++ show (windowMove opts)
