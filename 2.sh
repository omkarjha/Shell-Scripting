#!/bin/bash

file_path="/path/to/your/file"  # Replace with the actual file path

# Check if the file exists
if [ -e "$file_path" ]; then
    echo "$file_path passwords are enabled."
    
    # Check if the user has write permissions to the file
    if [ -w "$file_path" ]; then
        echo "You have permissions to edit $file_path."
    else
        echo "You do NOT have permissions to edit $file_path."
    fi
else
    echo "$file_path does not exist."
fi
