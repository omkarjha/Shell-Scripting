#!/bin/bash
read -p "Enter the filename: " filename
read -p "Enter the word to search: " word

if [[ -f $filename ]]; then
  count=$(grep -o "\b$word\b" "$filename" | wc -l)
  echo "The word '$word' occurs $count times in the file '$filename'."
else
  echo "File not found!"
fi
