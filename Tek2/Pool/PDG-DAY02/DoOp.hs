{-
-- EPITECH PROJECT, 2023
-- DoOp.hs
-- File description:
-- Day 2
-}

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem n (x:xs)
  | x == n = True
  | otherwise = myElem n xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv x y = Just (div x y)

safeNth :: [a] -> Int -> Maybe a
safeNth (x:xs) 0 = Just x
safeNth (x:xs) n
    | (n > length (x:xs)) = Nothing
    | (n < 0) = Nothing
safeNth (_:xs) n = safeNth xs (n-1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just n) = Just (n + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup n ((x, b):xs) 
    | x == n = (Just b)
    | otherwise = myLookup n xs