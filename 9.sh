#Write script called say_hello, which will print greetings based on time

#!/bin/bash

# Get the current hour
current_hour=$(date +"%H")

# Determine the appropriate greeting based on the time
if [ "$current_hour" -ge 5 -a "$current_hour" -lt 12 ]; then
    greeting="Good morning!"
elif [ "$current_hour" -ge 12 -a "$current_hour" -lt 17 ]; then
    greeting="Good afternoon!"
else
    greeting="Good evening!"
fi

# Print the greeting
echo "$greeting"
