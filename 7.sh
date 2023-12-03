#Write a script to compare larger integer values from a ‘n’ number of arguments using command line arguments

#!/bin/bash

# Check if at least two arguments are provided
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <integer1> <integer2> [integer3 ...]"
    exit 1
fi

largest=$1

# Iterate through the arguments to find the largest
for arg in "$@"; do
    if [ "$arg" -gt "$largest" ]; then
        largest=$arg
    fi
done

echo "The largest integer is: $largest"
