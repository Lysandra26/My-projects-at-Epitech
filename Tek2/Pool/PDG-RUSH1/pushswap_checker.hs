{-
-- EPITECH PROJECT, 2023
-- pushswap_checker.hs
-- File description:
-- Rush 1
-}

import Data.Char
import System.Environment
import System.Exit

myHead :: [a] -> [a]
myHead (a:_) = [a]
myHead [] = error "empty list"

myTake :: Int -> [a] -> [a]
myTake n (x:xs)
    | (n < 0) = (x:xs)
myTake 0 _ = []
myTake _ [] = []
myTake n (x:xs) = x:myTake (n - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop n _
    | (n < 0) = []
myDrop _ [] = []
myDrop 0 xs = xs
myDrop n (x:xs) = myDrop (n - 1) xs

myL :: [a] -> Int
myL [] = 0
myL (_:a) = 1 + myL a

myAppend :: [a] -> [a] -> [a]
myAppend [] ys = ys
myAppend (x:xs) ys = x : myAppend xs ys

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

sa :: [a] -> [a]
sa [] = []
sa (x:y:xs) = y:x:xs
sa xs = xs

sb :: [a] -> [a]
sb [] = []
sb (x:y:xs) = y:x:xs
sb xs = xs

pa :: [a] -> [a] -> [a]
pa l_a [] = l_a
pa l_a (x:xs) = x : l_a

pb :: [a] -> [a] -> [a]
pb [] l_b = l_b
pb (x:xs) l_b = x : l_b

ra :: [a] -> [a]
ra [] = []
ra l_a = case l_a of
    x:xs -> (myDrop 1 (x:xs)) ++ (myTake 1 (x:xs))

rb :: [a] -> [a]
rb [] = []
rb l_b = case l_b of
    x:xs -> (myDrop 1 (x:xs)) ++ (myTake 1 (x:xs))

rra :: [a] -> [a]
rra [] = []
rra l_a = case l_a of
    x:xs -> (myHead (myReverse (x:xs))) ++ (myTake ((myL (x:xs)) - 1) (x:xs))

rrb :: [a] -> [a]
rrb [] = []
rrb l_b = case l_b of
    x:xs -> (myHead (myReverse (x:xs))) ++ (myTake ((myL (x:xs)) - 1) (x:xs))

isSorted :: [String] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted (x:y:xs) = (x <= y) && isSorted (y:xs)

errorOK :: [String] -> [String] -> IO ()
errorOK l_a l_b = case l_b of
    (x:xs) -> if (myL (x:xs)) == 1
    then putStr "KO: " >>
        putStrLn ("(" ++ show l_a ++ ",[" ++ show (head l_b) ++ "])") >>
            exitWith (ExitFailure 84)
    else putStr "KO: " >>
        putStrLn ("(" ++ show l_a ++ "," ++ show l_b ++ ")") >>
            exitWith (ExitFailure 84)

ifSorted :: [String] -> [String] -> IO ()
ifSorted l_a l_b
    | l_b /= [] = errorOK l_a l_b
ifSorted l_a l_b
    | isSorted l_a == True = putStrLn "OK" >> return ()
    | otherwise = putStr "KO: " >>
        putStrLn ("(" ++ show l_a ++ ")") >>
            exitWith (ExitFailure 84)

strToWordList :: String -> [String]
strToWordList s = words s

strToWordList2 :: [String] -> [String]
strToWordList2 strs = concatMap words strs

mySnd :: [String] -> [String]
mySnd [] = []
mySnd (x:xs) = xs

sortAlgo2 :: [String] -> [String] -> [String] -> IO ()
sortAlgo2 [] l_a l_b = ifSorted l_a l_b
sortAlgo2 (x:xs) l_a l_b = case x of
    "ra" -> sortAlgo2 xs (ra l_a) l_b
    "rb" -> sortAlgo2 xs l_a (rb l_b)
    "rr" -> sortAlgo2 xs (ra l_a) (rb l_b)
    "rra" -> sortAlgo2 xs (rra l_a) l_b
    "rrb" -> sortAlgo2 xs l_a (rrb l_b)
    "rrr" -> sortAlgo2 xs (rra l_a) (rrb l_b)
    _ -> errorOK l_a l_b

sortAlgo :: [String] -> [String] -> [String] -> IO ()
sortAlgo [] l_a l_b = ifSorted l_a l_b
sortAlgo (x:xs) l_a l_b = case x of
    "sa" -> sortAlgo xs (sa l_a) l_b
    "sb" -> sortAlgo xs l_a (sb l_b)
    "sc" -> sortAlgo xs (sa l_a) (sb l_b)
    "pa" -> sortAlgo xs (pa l_a l_b) (mySnd l_b)
    "pb" -> sortAlgo xs (mySnd l_a) (pb l_a l_b)
    _ -> sortAlgo2 (x:xs) l_a l_b

printAll :: [String] -> [String] -> IO ()
printAll manualList listToSort
    | isSorted listToSort == True = putStrLn "OK"
    | otherwise = sortAlgo manualList listToSort []

main :: IO ()
main = do
    listToSort <- getArgs
    manualList <- getContents
    if listToSort == [] || manualList == []
        then exitWith (ExitFailure 84)
        else printAll (strToWordList2 (strToWordList manualList)) listToSort