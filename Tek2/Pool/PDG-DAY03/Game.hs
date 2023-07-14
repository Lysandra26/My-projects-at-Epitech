{-
-- EPITECH PROJECT, 2023
-- Game.hs
-- File description:
-- Day 3
-}

data Item = Sword | Bow | MagicWand deriving (Eq)
data Mob = Mummy | Skeleton | Witch deriving (Eq, Show)

instance Show Item where
    show Sword = "sword"
    show Bow   = "bow"
    show MagicWand = "magic wand"