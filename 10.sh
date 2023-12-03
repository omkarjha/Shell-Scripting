# Write a script to locks down file permissions for a particular directory. Display the status of the directory before and after the permission changed

#!/bin/bash

directory="/path/to/your/directory"  # Replace with the actual directory path

# Display current permissions
echo "Current permissions for $directory:"
ls -ld "$directory"

# Lock down file permissions
chmod -R go-rwx "$directory"

# Display updated permissions
echo -e "\nUpdated permissions for $directory:"
ls -ld "$directory"
