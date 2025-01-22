#!/bin/bash
read -p "Enter your age: " age

if ((age >= 18)); then
  echo "You are eligible to vote."
else
  echo "You are not eligible to vote."
fi
