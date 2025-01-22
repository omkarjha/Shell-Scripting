#!/bin/bash
echo "Parent process: $$"

# Create a child process
( 
  echo "Child process: $$"
  sleep 2
  echo "Child process finished."
) &

echo "Parent process continues..."
wait
echo "Parent process finished."
