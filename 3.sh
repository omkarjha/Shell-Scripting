# Write a shell script that consists of a function that displays the number of files with directory name in a directory. Name this function “file_count” and call it in your script. If you use variable in your function, remember to make it a local variable.

#!/bin/bash

# Define the function file_count
file_count() {
    local directory="$1"

    # Check if the directory exists
    if [ -d "$directory" ]; then
        # Count the number of files in the directory
        local count=$(find "$directory" -maxdepth 1 -type f | wc -l)

        echo "Number of files in $directory: $count"
        echo "File names:"
        
        # List the names of the files in the directory
        if [ "$count" -gt 0 ]; then
            find "$directory" -maxdepth 1 -type f -exec basename {} \;
        else
            echo "No files found."
        fi
    else
        echo "Directory $directory does not exist."
    fi
}

# Call the function with a specific directory path
file_count "/path/to/your/directory"  # Replace with the actual directory path
