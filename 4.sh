# Write a shell script function to receive system date and check current year is leap year or not

#!/bin/bash

# Function to check if a year is a leap year
check_leap_year() {
    local current_year=$(date +"%Y")

    # Check if the current year is divisible by 4 but not by 100, or if it's divisible by 400
    if [ $((current_year % 4)) -eq 0 ] && [ $((current_year % 100)) -ne 0 ] || [ $((current_year % 400)) -eq 0 ]; then
        echo "$current_year is a leap year."
    else
        echo "$current_year is not a leap year."
    fi
}

# Call the function to check if the current year is a leap year
check_leap_year
