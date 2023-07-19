{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-MPL-4-1-compressor-nicolas.lefevre
-- File description:
-- Algo
-}

module Algo (initAlgo, startAlgo, euclideanDistance) where

import Imports
import Parsing
import Tools
import qualified Data.Vector as V

initAlgo :: [String] -> IO ()
initAlgo args = do
    let lastArg = last args
    result <- fileIsExists lastArg
    when (result == 1) $
        errorExit "Error: File does not exist"
    contents <- parseFile lastArg
    when (isGood contents == 0) $ startAlgo args contents
    when (isGood contents /= 0) $
        errorExit "Error: Wrong filepath or wrong data inside it"

divList :: [Int] -> Int -> [Int]
divList lst n = map (\x -> x `div` n) lst

randomCenters :: Int -> [[Int]] -> IO [[Int]]
randomCenters k contents = do
  indices <- take k <$> nub <$> replicateM (k * 10)
    (randomRIO (0, length contents - 1))
  let centers = map (\i -> contents !! i) indices
  return centers

assignClusters :: [[Int]] -> [[Int]] -> V.Vector Int
assignClusters pixels centers = V.fromList $ map findNearestCenter pixels
  where
    findNearestCenter pixel = minimumIndex $ map (distance pixel) centers
    distance pixel center = sqrt $ fromIntegral $ sum $ zipWith
      (\p c -> (p - c) ^ (2 :: Integer)) pixel center
    minimumIndex xs = snd $ minimum $ zip xs [0..]

updateCenters :: Int -> [[Int]] -> V.Vector Int -> [[Int]]
updateCenters k pixels clusters = map calculateNewCenter [0..k-1]
  where
    calculateNewCenter i = divList (sumPoints i) (countPoints i)
    sumPoints i = foldl (\acc (j, p) -> if clusters V.! j == i
      then zipWith (+) acc p
        else acc) [0, 0, 0] $ zip [0..] pixels
    countPoints i = length $ filter
      (\(j, _) -> clusters V.! j == i) $ zip [0..] pixels

kMeans :: Int -> Int -> [[Int]] -> [[Int]] -> [[Int]]
kMeans k iterations pixels centers = go iterations centers
  where
    go 0 cs = cs
    go n cs = go (n-1) newCenters
      where
        clusters = assignClusters pixels cs
        newCenters = updateCenters k pixels clusters

startAlgo :: [String] -> [[Int]] -> IO ()
startAlgo args contents = do
  let k = findK args
      iterations = 10
  centers <- randomCenters k contents
  let clusters = kMeans k iterations contents centers
  print clusters

contentsToPixels :: [[Int]] -> [[Int]]
contentsToPixels contents = map (\xs ->
  case xs of [_y, _x, r, g, b] -> [r, g, b]; _ -> []) contents

euclideanDistance :: (Floating a) => (a, a, a) -> (a, a, a) -> a
euclideanDistance (x1, y1, z1) (x2, y2, z2) =
  sqrt ((x2-x1)^(2 :: Int) + (y2-y1)^(2 :: Int) + (z2-z1)^(2 :: Int))

-- meanColor :: [Color] -> Color
-- meanColor [] = error "Empty list"
-- meanColor xs = (round $ sumR / len, round $ sumG / len, round $ sumB / len)
--   where
--     len = fromIntegral $ length xs
--     sumR = fromIntegral $ sum [r | (r, _, _) <- xs]
--     sumG = fromIntegral $ sum [g | (_, g, _) <- xs]
--     sumB = fromIntegral $ sum [b | (_, _, b) <- xs]