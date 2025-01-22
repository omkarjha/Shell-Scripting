#!/bin/bash
read -p "Enter a number: " num
is_prime=1

for ((i=2; i<=num/2; i++)); do
  if ((num % i == 0)); then
    is_prime=0
    break
  fi
done

if ((is_prime == 1)); then
  echo "$num is a prime number."
else
  echo "$num is not a prime number."
fi
