#Write a script to print a given number in reverse order

#!/bin/bash

# Check if an argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

number=$1

# Use awk to reverse the digits of the number
reversed_number=$(echo "$number" | awk '{for(i=length;i!=0;i--)x=x substr($0,i,1)}END{print x}')

echo "Original number: $number"
echo "Reversed number: $reversed_number"