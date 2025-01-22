#!/bin/bash

factorial() {
    local num=$1
    if [ "$num" -le 1 ]; then
        echo 1
    else
        echo $((num * $(factorial $((num - 1)))))
    fi
}

echo "Enter a number: " 
read input_num
result=$(factorial "$input_num")
echo "The factorial of $input_num is $result"
