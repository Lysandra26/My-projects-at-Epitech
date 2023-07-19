#!/bin/bash

FILE_PATH="html/index.html"

if command -v google-chrome >/dev/null 2>&1; then
    google-chrome "$FILE_PATH"
    exit
elif command -v firefox >/dev/null 2>&1; then
    firefox "$FILE_PATH"
    exit
elif command -v microsoft-edge >/dev/null 2>&1; then
    microsoft-edge "$FILE_PATH"
    exit
elif command -v opera >/dev/null 2>&1; then
    opera "$FILE_PATH"
    exit
elif command -v brave >/dev/null 2>&1; then
    brave "$FILE_PATH"
    exit
else
    echo "Aucun navigateur compatible (Google Chrome, Firefox, Microsoft Edge, Opera ou Brave) n'est installé sur ce système."
fi
