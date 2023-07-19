{-
-- EPITECH PROJECT, 2023
-- B-FUN-400-MPL-4-1-compressor-nicolas.lefevre
-- File description:
-- Imports
-}

module Imports (
    module System.Exit,
    module Text.Read,
    module System.IO,
    module System.Random,
    module Control.Monad,
    module Data.List,
    module System.Environment
) where

import System.Exit (exitWith, ExitCode(ExitFailure))
import Text.Read (readMaybe)
import System.IO
import System.Random
import Control.Monad (replicateM)
import Data.List (nub, find)
import System.Environment (getArgs)
import Control.Monad (when, forM)
