{-
-- EPITECH PROJECT, 2023
-- My.hs
-- File description:
-- Day 1
-}

mySucc :: Int -> Int
mySucc n = n + 1

myIsNeg :: Int -> Bool
myIsNeg n
    | (n < 0) = True
    | otherwise = False

myAbs :: Int -> Int
myAbs n
    | (n > 0) = n
    | otherwise = (n * (-1))

myMin :: Int -> Int -> Int
myMin a b
    | (a > b) = b
    | otherwise = a

myMax :: Int -> Int -> Int
myMax a b
    | (a > b) = a
    | otherwise = b

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "empty list"
myHead (a:_) = a

myTail :: [a] -> [a]
myTail [] = error "empty list"
myTail (_:a) = a

myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth (x:xs) 0 = x
myNth (x:xs) n
    | (n > myLength(x:xs)) = error "index is too large"
    | (n < 0) = error "index is negative"
myNth (_:xs) n = myNth xs (n-1)
