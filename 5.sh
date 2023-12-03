# Write shell script to design calculator using function and switch case

#!/bin/bash

# Function to perform addition
addition() {
    result=$(echo "$1 + $2" | bc)
    echo "Result: $result"
}

# Function to perform subtraction
subtraction() {
    result=$(echo "$1 - $2" | bc)
    echo "Result: $result"
}

# Function to perform multiplication
multiplication() {
    result=$(echo "$1 * $2" | bc)
    echo "Result: $result"
}

# Function to perform division
division() {
    if [ "$2" -eq 0 ]; then
        echo "Error: Division by zero is not allowed."
    else
        result=$(echo "scale=2; $1 / $2" | bc)
        echo "Result: $result"
    fi
}

# Main calculator function
calculator() {
    echo "Select operation:"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"

    read -p "Enter choice (1/2/3/4): " choice

    case $choice in
        1)
            read -p "Enter first number: " num1
            read -p "Enter second number: " num2
            addition "$num1" "$num2"
            ;;
        2)
            read -p "Enter first number: " num1
            read -p "Enter second number: " num2
            subtraction "$num1" "$num2"
            ;;
        3)
            read -p "Enter first number: " num1
            read -p "Enter second number: " num2
            multiplication "$num1" "$num2"
            ;;
        4)
            read -p "Enter first number: " num1
            read -p "Enter second number: " num2
            division "$num1" "$num2"
            ;;
        *)
            echo "Invalid choice. Please enter a valid option (1/2/3/4)."
            ;;
    esac
}

# Call the main calculator function
calculator
