{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-MPL-4-1-compressor-nicolas.lefevre
-- File description:
-- RandomPoints
-}

module RandomPoints (randomCentroids, findRandomPoints, findColorsOfPoints) where

import Imports
import Tools

randomCentroids :: Int -> [[Int]] -> IO [[Int]]
randomCentroids k points = do
  gen <- newStdGen
  let indices = take k $ randomRs (0, length points - 1) gen
  return $ map (points !!) indices

findColorOfPoint :: [Int] -> [[Int]] -> IO [Int]
findColorOfPoint randomPoint colorList =
  case find (\l -> take 2 l == randomPoint) colorList of
  Just colors -> return colors
  Nothing -> return []

findColorsOfPoints :: [[Int]] -> [[Int]] -> IO [[Int]]
findColorsOfPoints [] _ = return []
findColorsOfPoints (x:xs) colorList = do
  colors <- findColorOfPoint x colorList
  rest <- findColorsOfPoints xs colorList
  return $ colors : rest

generateRandomPoint :: [[Int]] -> IO [Int]
generateRandomPoint list = do
    let maxY = getLastListElement (last list) 0
        maxX = getLastListElement (last list) 1
    y <- randomRIO (0, maxY)
    x <- randomRIO (0, maxX)
    return [y, x]

generateRandomPoints :: Int -> [[Int]] -> IO [[Int]]
generateRandomPoints k contents = replicateM k (generateRandomPoint contents)

findRandomPoints :: Int -> [[Int]] -> IO [[Int]]
findRandomPoints k contents =
    let loop pointsPos = do
            newPoints <- generateRandomPoints k contents
            if hasDuplicates (pointsPos ++ newPoints) == -1
                then loop pointsPos
            else return (pointsPos ++ newPoints)
    in loop []