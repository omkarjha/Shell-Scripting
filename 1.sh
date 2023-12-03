# write a shell script that prompts the user for a name of a file or directory and reports if it is a regular file, a directory, or another type of file. Also perform an ls command against the file or directory with the long listing option.

read -p "Enter the name of file or directory:" user_input

# Check if enterd path exists
if [-e "$user_input"];then

    #Check if it's a regular file
    if[-f "$user_input"];then
        echo "$user_input is a regular file."

    # Check if it's a directory
    elif[-d "$user_input"];then
        echo "$user_inpuy is a directory."

    # If it's neither a file or directory
    else
        echo "$user_input is another type of file."
    fi

    #Performing an ls command with ls option 
    ls -l "$user_input"

else 
    echo "The specified file path or directory doesn't exist."
fi